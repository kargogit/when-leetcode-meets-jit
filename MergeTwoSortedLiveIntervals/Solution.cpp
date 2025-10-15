#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for a live interval node.
 */
struct IntervalNode {
    int start_idx;
    int end_idx;
    IntervalNode* next;

    IntervalNode() : start_idx(0), end_idx(0), next(nullptr) {}
    IntervalNode(int s, int e) : start_idx(s), end_idx(e), next(nullptr) {}
    IntervalNode(int s, int e, IntervalNode* next) : start_idx(s), end_idx(e), next(next) {}
};

class CompilerCFG {
public:
    IntervalNode* mergeLiveIntervalLists(IntervalNode* blockA, IntervalNode* blockB) {
        if (!blockA) return blockB;
        if (!blockB) return blockA;

        IntervalNode dummy;
        IntervalNode* tail = &dummy;

        while (blockA && blockB) {
            if (blockA->start_idx <= blockB->start_idx) {
                tail->next = blockA;
                blockA = blockA->next;
            } else {
                tail->next = blockB;
                blockB = blockB->next;
            }
            tail = tail->next;
        }

        tail->next = blockA ? blockA : blockB;
        return dummy.next;
    }
};

static IntervalNode* buildList(const vector<pair<int, int>>& intervals) {
    IntervalNode dummy;
    IntervalNode* tail = &dummy;

    for (const auto& p : intervals) {
        tail->next = new IntervalNode(p.first, p.second);
        tail = tail->next;
    }

    return dummy.next;
}

static void printList(IntervalNode* head) {
    if (!head) {
        cout << "[]\n";
        return;
    }

    while (head) {
        cout << "[" << head->start_idx << ", " << head->end_idx << "]";
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << '\n';
}

static void deleteList(IntervalNode* head) {
    while (head) {
        IntervalNode* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    CompilerCFG solver;

    IntervalNode* blockA1 = buildList({{1, 4}, {5, 9}, {10, 12}});
    IntervalNode* blockB1 = buildList({{2, 6}, {5, 8}, {14, 20}});
    IntervalNode* merged1 = solver.mergeLiveIntervalLists(blockA1, blockB1);
    printList(merged1);
    deleteList(merged1);

    IntervalNode* blockA2 = buildList({});
    IntervalNode* blockB2 = buildList({});
    IntervalNode* merged2 = solver.mergeLiveIntervalLists(blockA2, blockB2);
    printList(merged2);
    deleteList(merged2);

    IntervalNode* blockA3 = buildList({});
    IntervalNode* blockB3 = buildList({{0, 5}});
    IntervalNode* merged3 = solver.mergeLiveIntervalLists(blockA3, blockB3);
    printList(merged3);
    deleteList(merged3);

    return 0;
}
