#include <iostream>

struct IRInstruction {
    int opcode;
    IRInstruction* next;

    IRInstruction() : opcode(0), next(nullptr) {}
    IRInstruction(int val) : opcode(val), next(nullptr) {}
    IRInstruction(int val, IRInstruction* nxt) : opcode(val), next(nxt) {}
};

class Solution {
public:
    IRInstruction* reverseIRInstructionList(IRInstruction* head) {
        IRInstruction* prev = nullptr;
        IRInstruction* curr = head;

        while (curr != nullptr) {
            IRInstruction* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
};


IRInstruction* buildList(const std::initializer_list<int>& values) {
    IRInstruction* head = nullptr;
    IRInstruction* tail = nullptr;

    for (int val : values) {
        IRInstruction* node = new IRInstruction(val);
        if (!head) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
    }

    return head;
}

void printList(IRInstruction* head) {
    std::cout << "[";
    while (head != nullptr) {
        std::cout << head->opcode;
        if (head->next) std::cout << ", ";
        head = head->next;
    }
    std::cout << "]" << std::endl;
}

void freeList(IRInstruction* head) {
    while (head) {
        IRInstruction* tmp = head;
        head = head->next;
        delete tmp;
    }
}

int main() {
    Solution sol;

    IRInstruction* list1 = buildList({10, 20, 30, 40, 50});
    std::cout << "Input:  ";
    printList(list1);
    list1 = sol.reverseIRInstructionList(list1);
    std::cout << "Output: ";
    printList(list1);
    freeList(list1);

    std::cout << std::endl;

    IRInstruction* list2 = buildList({10, 20});
    std::cout << "Input:  ";
    printList(list2);
    list2 = sol.reverseIRInstructionList(list2);
    std::cout << "Output: ";
    printList(list2);
    freeList(list2);

    std::cout << std::endl;

    IRInstruction* list3 = buildList({});
    std::cout << "Input:  ";
    printList(list3);
    list3 = sol.reverseIRInstructionList(list3);
    std::cout << "Output: ";
    printList(list3);
    freeList(list3);

    return 0;
}
