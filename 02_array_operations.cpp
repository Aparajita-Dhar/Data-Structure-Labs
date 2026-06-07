#include <iostream>

/* Topic 2: Array Operations
   Manages linear array transformations using class execution controls.
*/
class ArrayManager {
private:
    int data[10];
    int currentSize;

public:
    ArrayManager() {
        // Initializing with sample records
        data[0] = 10; data[1] = 20; data[2] = 30; data[3] = 40; data[4] = 50;
        currentSize = 5;
    }

    void traverseAndPrint() {
        for (int i = 0; i < currentSize; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << "\n";
    }

    void insertElement(int index, int value) {
        if (currentSize >= 10 || index > currentSize) return;

        // Shift elements down to make a gap
        for (int i = currentSize; i > index; i--) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        currentSize++;
    }

    void deleteElement(int index) {
        if (index >= currentSize) return;

        // Shift elements up to overwrite the target
        for (int i = index; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }
        currentSize--;
    }
};

int main() {
    ArrayManager manager;

    std::cout << "--- 1. Initial Array Traversal ---\n";
    manager.traverseAndPrint();

    std::cout << "\n--- 2. Inserting 99 at Index 2 ---\n";
    manager.insertElement(2, 99);
    manager.traverseAndPrint();

    std::cout << "\n--- 3. Deleting Element at Index 3 ---\n";
    manager.deleteElement(3);
    manager.traverseAndPrint();

    return 0;
}
