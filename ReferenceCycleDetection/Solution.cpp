#include <iostream>

struct HeapObject {
    int id;
    HeapObject* next;
    HeapObject(int val) : id(val), next(nullptr) {}
};

class GarbageCollector {
public:
    bool hasReferenceCycle(HeapObject* start) {
        HeapObject* slow = start;
        HeapObject* fast = start;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};

int main() {
    HeapObject* obj0 = new HeapObject(0);
    HeapObject* obj1 = new HeapObject(1);
    HeapObject* obj2 = new HeapObject(2);
    obj0->next = obj1;
    obj1->next = obj2;
    obj2->next = obj1;

    GarbageCollector gc;
    std::cout << "Example 1 (expect true):  " << (gc.hasReferenceCycle(obj0) ? "true" : "false") << "\n";

    obj2->next = nullptr;
    delete obj0;
    delete obj1;
    delete obj2;

    HeapObject* a = new HeapObject(0);
    HeapObject* b = new HeapObject(1);
    HeapObject* c = new HeapObject(2);
    a->next = b;
    b->next = c;

    std::cout << "Example 2 (expect false): " << (gc.hasReferenceCycle(a) ? "true" : "false") << "\n";

    delete a;
    delete b;
    delete c;

    HeapObject* lone = new HeapObject(0);
    std::cout << "Single node (expect false): " << (gc.hasReferenceCycle(lone) ? "true" : "false") << "\n";
    delete lone;

    HeapObject* self = new HeapObject(0);
    self->next = self;
    std::cout << "Self-loop (expect true):  " << (gc.hasReferenceCycle(self) ? "true" : "false") << "\n";
    self->next = nullptr;
    delete self;

    std::cout << "Null start (expect false): " << (gc.hasReferenceCycle(nullptr) ? "true" : "false") << "\n";

    return 0;
}
