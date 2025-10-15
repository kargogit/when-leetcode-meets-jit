#include <iostream>
#include <stack>

struct VTableNode {
    int memory_offset;
    VTableNode *left;
    VTableNode *right;

    VTableNode() : memory_offset(0), left(nullptr), right(nullptr) {}
    VTableNode(int x) : memory_offset(x), left(nullptr), right(nullptr) {}
    VTableNode(int x, VTableNode *left, VTableNode *right) : memory_offset(x), left(left), right(right) {}
};

class DispatchTableOptimizer {
public:
    int kthSmallestOffset(VTableNode* root, int k) {
        std::stack<VTableNode*> stk;
        VTableNode* curr = root;

        while (curr || !stk.empty()) {
            // Go as far left as possible
            while (curr) {
                stk.push(curr);
                curr = curr->left;
            }

            curr = stk.top();
            stk.pop();

            // Each pop is the next smallest element
            if (--k == 0)
                return curr->memory_offset;

            curr = curr->right;
        }

        return -1; // k was out of range, shouldn't happen per constraints
    }
};


VTableNode* insert(VTableNode* root, int val) {
    if (!root) return new VTableNode(val);
    if (val < root->memory_offset)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}


void freeTree(VTableNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    DispatchTableOptimizer optimizer;

    VTableNode* root1 = new VTableNode(30,
        new VTableNode(10, nullptr, new VTableNode(20)),
        new VTableNode(40)
    );
    std::cout << "Example 1: " << optimizer.kthSmallestOffset(root1, 1) << "\n"; // 10
    freeTree(root1);

    VTableNode* root2 = new VTableNode(50,
        new VTableNode(30,
            new VTableNode(20, new VTableNode(10), nullptr),
            new VTableNode(40)
        ),
        new VTableNode(60)
    );
    std::cout << "Example 2: " << optimizer.kthSmallestOffset(root2, 3) << "\n"; // 30
    freeTree(root2);

    return 0;
}
