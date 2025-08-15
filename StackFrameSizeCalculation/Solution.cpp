#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;

// Represents a lexical scope or activation record in the AST
struct ScopeNode {
    int id;
    std::vector<ScopeNode*> children;

    ScopeNode() : id(0) {}
    explicit ScopeNode(int _id) : id(_id) {}
    ScopeNode(int _id, std::vector<ScopeNode*> _children)
        : id(_id), children(std::move(_children)) {}
};

class Solution {
public:
    /**
     * PATCG Phase: Program Analysis -> Frame Allocation
     * Computes the maximum nesting depth of scopes to determine
     * the exact stack frame size required for code generation.
     *
     * @param root Pointer to the root scope node (may be nullptr)
     * @return Maximum scope depth (integer >= 0)
     */

    int calculateFrameSize(ScopeNode* root) {
        int frameSize = 0;
        if ( root == nullptr ) return 0;

        stack<pair<ScopeNode*, int>> scopeTracker;
        scopeTracker.push( { root, 1 } );
        while ( ! scopeTracker.empty() ) {
            auto [node, currDepth] = scopeTracker.top();
            scopeTracker.pop();
            frameSize = max(frameSize, currDepth);

            for ( auto child : node -> children )
                scopeTracker.push( { child, currDepth + 1 } );
        }
        return frameSize;
    }
};

int main() {
    ScopeNode* node5 = new ScopeNode(5);
    ScopeNode* node4 = new ScopeNode(4, {node5});
    ScopeNode* node3 = new ScopeNode(3);
    ScopeNode* node2 = new ScopeNode(2, {node4});
    ScopeNode* root  = new ScopeNode(1, {node2, node3});

    Solution sol;
    int result = sol.calculateFrameSize(root);

    cout << "Maximum scope depth / frame size: " << result << endl;

    delete node5;
    delete node4;
    delete node3;
    delete node2;
    delete root;

    return 0;
}
