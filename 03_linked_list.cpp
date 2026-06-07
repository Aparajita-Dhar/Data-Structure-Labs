#include <iostream>

/* Topic 3: Singly Linked List Implementation
   Demonstrates heap allocations using modern C++ memory handles ('new' and 'delete').
*/
class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {} // Constructor for easy node creation
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    // Destructor to free heap allocations automatically when out of scope
    ~SinglyLinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp; // C++ free memory mechanism
        }
    }

    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};

int main() {
    SinglyLinkedList list;
    std::cout << "--- Building Dynamic Object-Oriented Linked List ---\n";
    
    list.insertAtHead(40);
    list.insertAtHead(30);
    list.insertAtHead(20);
    list.insertAtHead(10);

    list.display();
    return 0;
}
