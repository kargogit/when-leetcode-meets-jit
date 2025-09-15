#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* buildBinaryJumpTable(vector<int>& caseValues) {
        if (caseValues.empty()) return nullptr;
        return build(caseValues, 0, caseValues.size() - 1);
    }

private:
    TreeNode* build(vector<int>& vals, int lo, int hi) {
        if (lo > hi) return nullptr;

        int mid = lo + (hi - lo) / 2;
        TreeNode* node = new TreeNode(vals[mid]);
        node->left  = build(vals, lo, mid - 1);
        node->right = build(vals, mid + 1, hi);
        return node;
    }
};


void printLevelOrder(TreeNode* root) {
    if (!root) {
        cout << "[]" << endl;
        return;
    }

    queue<TreeNode*> q;
    q.push(root);
    vector<string> result;

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();

        if (curr) {
            result.push_back(to_string(curr->val));
            q.push(curr->left);
            q.push(curr->right);
        } else {
            result.push_back("null");
        }
    }

    while (!result.empty() && result.back() == "null")
        result.pop_back();

    cout << "[";
    for (int i = 0; i < (int)result.size(); i++) {
        if (i > 0) cout << ", ";
        cout << result[i];
    }
    cout << "]" << endl;
}

void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    vector<int> case1 = {-10, -3, 0, 5, 9};
    TreeNode* tree1 = sol.buildBinaryJumpTable(case1);
    cout << "Example 1: ";
    printLevelOrder(tree1);
    freeTree(tree1);

    vector<int> case2 = {1, 3};
    TreeNode* tree2 = sol.buildBinaryJumpTable(case2);
    cout << "Example 2: ";
    printLevelOrder(tree2);
    freeTree(tree2);

    vector<int> case3 = {};
    TreeNode* tree3 = sol.buildBinaryJumpTable(case3);
    cout << "Example 3 (empty): ";
    printLevelOrder(tree3);

    vector<int> case4 = {42};
    TreeNode* tree4 = sol.buildBinaryJumpTable(case4);
    cout << "Example 4 (single): ";
    printLevelOrder(tree4);
    freeTree(tree4);

    return 0;
}
