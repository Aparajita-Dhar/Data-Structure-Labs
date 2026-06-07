#include <iostream>
#define CAPACITY 5

/* Topic 4: Stack Implementation (LIFO) */
class ArrayStack {
private:
    int storage[CAPACITY];
    int topIndex;

public:
    ArrayStack() : topIndex(-1) {}

    bool isFull() { return topIndex == CAPACITY - 1; }
    bool isEmpty() { return topIndex == -1; }

    void push(int item) {
        if (isFull()) {
            std::cout << "Stack Overflow!\n";
            return;
        }
        storage[++topIndex] = item;
        std::cout << "Pushed metric: " << item << "\n";
    }

    int pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow!\n";
            return -1;
        }
        return storage[topIndex--];
    }

    int peek() {
        if (isEmpty()) return -1;
        return storage[topIndex];
    }
};

int main() {
    std::cout << "--- Stack Architecture Diagnostics ---\n";
    ArrayStack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    std::cout << "Current Top Element: " << stack.peek() << "\n";
    std::cout << "Popped: " << stack.pop() << "\n";
    std::cout << "Current Top Element: " << stack.peek() << "\n";
    return 0;
}
