#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* findCompilationMidpoint(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

ListNode* buildList(std::initializer_list<int> vals) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

void freeList(ListNode* head) {
    while (head) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    ListNode* list1 = buildList({1, 3, 5, 7, 9});
    std::cout << "Example 1: " << sol.findCompilationMidpoint(list1)->val << "\n"; // 5
    freeList(list1);

    ListNode* list2 = buildList({2, 4, 6, 8});
    std::cout << "Example 2: " << sol.findCompilationMidpoint(list2)->val << "\n"; // 6
    freeList(list2);

    ListNode* list3 = buildList({42});
    std::cout << "Example 3: " << sol.findCompilationMidpoint(list3)->val << "\n"; // 42
    freeList(list3);

    return 0;
}
