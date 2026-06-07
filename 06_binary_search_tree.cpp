#include <iostream>

/* Topic 6: Processing Hierarchical Tree Data (Binary Search Tree)
   Uses an OOP layout to govern parent, left-child, and right-child pointer links.
*/
class BinarySearchTree {
private:
    struct TreeNode {
        int data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
    };

    TreeNode* root;

    // Private helper function to handle recursive insertions
    TreeNode* insertHelper(TreeNode* node, int value) {
        if (node == nullptr) {
            return new TreeNode(value);
        }
        if (value < node->data) {
            node->left = insertHelper(node->left, value);
        } else {
            node->right = insertHelper(node->right, value);
        }
        return node;
    }

    // Private helper function to handle recursive In-Order tree traversal
    void inorderHelper(TreeNode* node) {
        if (node != nullptr) {
            inorderHelper(node->left);
            std::cout << node->data << " ";
            inorderHelper(node->right);
        }
    }

    // Private helper function to recursively free memory upon destruction
    void destroyTree(TreeNode* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}
    
    // Destructor to prevent memory leaks on the heap
    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int value) {
        root = insertHelper(root, value);
    }

    void displayInOrder() {
        inorderHelper(root);
        std::cout << "\n";
    }
};

int main() {
    BinarySearchTree bst;
    std::cout << "--- Building C++ Object-Oriented Binary Search Tree ---\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);

    std::cout << "BST Traversal Output (Sorted Order via In-Order Parse):\n";
    bst.displayInOrder();

    return 0;
}
