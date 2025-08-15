#include <vector>
#include <iostream>

class Solution {
public:
    void compactHeap(std::vector<int>& heap) {
        int writePos = 0;

        for (int i = 0; i < (int)heap.size(); i++) {
            if (heap[i] != 0) {
                heap[writePos++] = heap[i];
            }
        }

        while (writePos < (int)heap.size()) {
            heap[writePos++] = 0;
        }
    }
};

int main() {
    Solution sol;

    std::vector<std::vector<int>> testCases = {
        {0, 1, 0, 3, 12},
        {0},
        {5, 2, 0, 7},
        {0, 0, 0, 0},
        {1, 2, 3, 4},
        {0, -5, 0, 3, 0, -1}
    };

    for (auto& heap : testCases) {
        std::cout << "Before: [";
        for (int i = 0; i < (int)heap.size(); i++) {
            std::cout << heap[i];
            if (i + 1 < (int)heap.size()) std::cout << ", ";
        }
        std::cout << "]\n";

        sol.compactHeap(heap);

        std::cout << "After:  [";
        for (int i = 0; i < (int)heap.size(); i++) {
            std::cout << heap[i];
            if (i + 1 < (int)heap.size()) std::cout << ", ";
        }
        std::cout << "]\n\n";
    }

    return 0;
}
