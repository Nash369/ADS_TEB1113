/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

// Node of the BST
struct Node {
    int data;
    Node* leftChild;
    Node* rightChild;

    Node(int value) {
        data = value;
        leftChild = nullptr;
        rightChild = nullptr;
    }
};

// Binary Search Tree
class BinarySearchTree {
private:
    Node* root;

    void inorder(Node* current) {
        if (current == nullptr)
            return;

        inorder(current->leftChild);
        cout << current->data << " ";
        inorder(current->rightChild);
    }

    void preorder(Node* current) {
        if (current == nullptr)
            return;

        cout << current->data << " ";
        preorder(current->leftChild);
        preorder(current->rightChild);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int value) {
        Node* newNode = new Node(value);

        if (root == nullptr) {
            root = newNode;
            return;
        }

        Node* current = root;

        while (true) {
            if (value < current->data) {
                if (current->leftChild == nullptr) {
                    current->leftChild = newNode;
                    break;
                }
                current = current->leftChild;
            }
            else if (value > current->data) {
                if (current->rightChild == nullptr) {
                    current->rightChild = newNode;
                    break;
                }
                current = current->rightChild;
            }
            else {
                delete newNode;   // Ignore duplicates
                break;
            }
        }
    }

    bool search(int value) {
        Node* current = root;

        while (current != nullptr) {
            if (value == current->data)
                return true;

            if (value < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
        }

        return false;
    }

    void displayInorder() {
        inorder(root);
    }

    void displayPreorder() {
        preorder(root);
    }
};

int main() {
    BinarySearchTree bst;

    int numbers[] = {4, 2, 6, 1, 3, 5, 7};

    for (int i = 0; i < 7; i++) {
        bst.insert(numbers[i]);
    }

    cout << "In-order Traversal: ";
    bst.displayInorder();
    cout << endl;

    cout << "Pre-order Traversal: ";
    bst.displayPreorder();
    cout << endl;

    cout << "Search 5: ";
    cout << (bst.search(5) ? "Found" : "Not Found") << endl;

    cout << "Search 9: ";
    cout << (bst.search(9) ? "Found" : "Not Found") << endl;

    return 0;
}