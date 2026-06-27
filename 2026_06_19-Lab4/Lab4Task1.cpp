/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;
    Node* prev;

    Node(string n) {
        name = n;
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            return;
        }

        Node* tail = head->prev;

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }

    void insertAfter(string afterName, string newName) {

        if (head == nullptr)
            return;

        Node* current = head;

        do {

            if (current->name == afterName) {

                Node* newNode = new Node(newName);

                Node* nextNode = current->next;

                newNode->next = nextNode;
                newNode->prev = current;

                current->next = newNode;
                nextNode->prev = newNode;

                if (current == head->prev)
                    head->prev = newNode;

                return;
            }

            current = current->next;

        } while (current != head);

        cout << afterName << " not found." << endl;
    }

    void deleteByName(string name) {

        if (head == nullptr)
            return;

        // only one node
        if (head->next == head && head->name == name) {
            delete head;
            head = nullptr;
            return;
        }

        // delete head
        if (head->name == name) {

            Node* tail = head->prev;
            Node* temp = head;

            head = head->next;

            tail->next = head;
            head->prev = tail;

            delete temp;
            return;
        }

        Node* current = head->next;

        while (current != head) {

            if (current->name == name) {

                current->prev->next = current->next;
                current->next->prev = current->prev;

                delete current;
                return;
            }

            current = current->next;
        }

        cout << name << " not found." << endl;
    }

    void display() {

        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }

    void displayReverse() {

        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head->prev;

        do {
            cout << current->name << endl;
            current = current->prev;
        } while (current != head->prev);
    }
};

int main() {

    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list\n";
    list.display();

    cout << "\nInsert Ali after Anjana\n";
    list.insertAfter("Anjana", "Ali");
    list.display();

    cout << "\nInsert Jane at end\n";
    list.insertEnd("Jane");
    list.display();

    cout << "\nDelete Jessy\n";
    list.deleteByName("Jessy");
    list.display();

    cout << "\nReverse display\n";
    list.displayReverse();

    cout << "\nFinal list\n";
    list.display();

    return 0;
}