#include <iostream>
#define Q_CAPACITY 5

/* Topic 5: Queue Implementation (FIFO) */
class ArrayQueue {
private:
    int storage[Q_CAPACITY];
    int front;
    int rear;
    int count;

public:
    ArrayQueue() : front(0), rear(-1), count(0) {}

    bool isFull() { return count == Q_CAPACITY; }
    bool isEmpty() { return count == 0; }

    void enqueue(int item) {
        if (isFull()) {
            std::cout << "Queue Overflow!\n";
            return;
        }
        rear = (rear + 1) % Q_CAPACITY; // Circular buffer safety logic
        storage[rear] = item;
        count++;
        std::cout << "Enqueued entry: " << item << "\n";
    }

    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue Underflow!\n";
            return -1;
        }
        int removed = storage[front];
        front = (front + 1) % Q_CAPACITY;
        count--;
        return removed;
    }
};

int main() {
    std::cout << "--- Queue Architecture Diagnostics ---\n";
    ArrayQueue queue;
    queue.enqueue(100);
    queue.enqueue(200);

    std::cout << "Processed from Front: " << queue.dequeue() << "\n";
    queue.enqueue(300);
    return 0;
}
