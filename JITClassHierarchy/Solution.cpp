#include <iostream>
#include <vector>

struct TypeNode {
    int type_id;
    TypeNode *left;
    TypeNode *right;
    TypeNode(int x) : type_id(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TypeNode* lowestCommonSuperclass(TypeNode* root, TypeNode* p, TypeNode* q) {
        TypeNode* curr = root;

        while (curr) {
            if (p->type_id < curr->type_id && q->type_id < curr->type_id) {
                curr = curr->left;
            } else if (p->type_id > curr->type_id && q->type_id > curr->type_id) {
                curr = curr->right;
            } else {
                return curr;
            }
        }

        return nullptr;
    }
};


TypeNode* buildBST(const std::vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;

    TypeNode* root = new TypeNode(vals[0]);
    std::vector<TypeNode*> queue = {root};
    int i = 1;
    int front = 0;

    while (front < (int)queue.size() && i < (int)vals.size()) {
        TypeNode* curr = queue[front++];

        if (i < (int)vals.size() && vals[i] != -1) {
            curr->left = new TypeNode(vals[i]);
            queue.push_back(curr->left);
        }
        i++;

        if (i < (int)vals.size() && vals[i] != -1) {
            curr->right = new TypeNode(vals[i]);
            queue.push_back(curr->right);
        }
        i++;
    }

    return root;
}

TypeNode* findNode(TypeNode* root, int val) {
    while (root) {
        if (val == root->type_id) return root;
        else if (val < root->type_id) root = root->left;
        else root = root->right;
    }
    return nullptr;
}

void freeTree(TypeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    Solution sol;

    {
        TypeNode* root = buildBST({10, 5, 15, 2, 7, 12, 20});
        TypeNode* p = findNode(root, 2);
        TypeNode* q = findNode(root, 7);
        TypeNode* result = sol.lowestCommonSuperclass(root, p, q);
        std::cout << "Example 1 - LCS: " << result->type_id << " (expected 5)\n";
        freeTree(root);
    }

    {
        TypeNode* root = buildBST({10, 5, 15});
        TypeNode* p = findNode(root, 5);
        TypeNode* q = findNode(root, 15);
        TypeNode* result = sol.lowestCommonSuperclass(root, p, q);
        std::cout << "Example 2 - LCS: " << result->type_id << " (expected 10)\n";
        freeTree(root);
    }

    {
        TypeNode* root = buildBST({10, 5, 15, 2, 7, 12, 20});
        TypeNode* p = findNode(root, 5);
        TypeNode* q = findNode(root, 2);
        TypeNode* result = sol.lowestCommonSuperclass(root, p, q);
        std::cout << "Example 3 - LCS: " << result->type_id << " (expected 5)\n";
        freeTree(root);
    }

    return 0;
}
