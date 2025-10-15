#include <iostream>
using namespace std;

/**
 * Definition for a Basic Block in a Control Flow Graph.
 */
struct BasicBlock {
    int blockId;
    BasicBlock* next;
    BasicBlock(int x) : blockId(x), next(nullptr) {}
};

class Solution {
public:
    BasicBlock* getConvergenceBlock(BasicBlock* pathA, BasicBlock* pathB) {
        BasicBlock* a = pathA;
        BasicBlock* b = pathB;

        while (a != b) {
            a = (a == nullptr) ? pathB : a->next;
            b = (b == nullptr) ? pathA : b->next;
        }

        return a;
    }
};

int main() {
    Solution solution;

    BasicBlock* block1 = new BasicBlock(1);
    BasicBlock* block2 = new BasicBlock(2);
    BasicBlock* block3 = new BasicBlock(3);
    BasicBlock* block4 = new BasicBlock(4);
    BasicBlock* block5 = new BasicBlock(5);
    BasicBlock* block6 = new BasicBlock(6);

    block1->next = block2;
    block2->next = block5;
    block3->next = block4;
    block4->next = block5;
    block5->next = block6;

    BasicBlock* ans1 = solution.getConvergenceBlock(block1, block3);
    if (ans1) {
        cout << "Example 1 convergence block: " << ans1->blockId << '\n';
    } else {
        cout << "Example 1 convergence block: null\n";
    }

    BasicBlock* a1 = new BasicBlock(10);
    BasicBlock* a2 = new BasicBlock(20);
    BasicBlock* b1 = new BasicBlock(30);
    BasicBlock* b2 = new BasicBlock(40);

    a1->next = a2;
    b1->next = b2;

    BasicBlock* ans2 = solution.getConvergenceBlock(a1, b1);
    if (ans2) {
        cout << "Example 2 convergence block: " << ans2->blockId << '\n';
    } else {
        cout << "Example 2 convergence block: null\n";
    }

    delete block1;
    delete block2;
    delete block3;
    delete block4;
    delete block5;
    delete block6;

    delete a1;
    delete a2;
    delete b1;
    delete b2;

    return 0;
}
