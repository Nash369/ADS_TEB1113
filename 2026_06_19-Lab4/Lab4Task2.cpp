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
    Node* next = NULL; //memory address of the next node
    Node* prev = NULL;
    Node(string n) {
        name = n; //the string will pass here to declare first
        next = nullptr;
        prev = nullptr;
    }
};

class LinkedList {
public:
    Node* head; //memory address of the first node

    LinkedList() {
        head = nullptr; //empty list
    }

    void insertEnd(string name) { //insert at the end
        Node* newNode = new Node(name);

        if (head == nullptr) {
            //meaning that the list is empty 
            head = newNode;
            return;
        }

        // if not walk to the last node
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        while (current != nullptr && current->name != afterName) {
            current = current->next;
            //find the postition to be inserted
        }

        if (current == nullptr) {
            cout << afterName << "not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        //Ali points to what Anjana is pointing
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
            // the node after must point back to the new node if 
            // after the new node, there is still node there
        }
        current->next = newNode;
  
    }

    //delete a node by the name 
    void deleteByName (string name) {
        if (head == nullptr) {
            return; //empty list
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            // new head has no previous node
            delete temp; // if the deleted one should be head
            return;
        }
        // search the rest of the list 
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next; //using this mean assigned the address to temp
                current->next = temp->next; 
                if (temp->next != nullptr) {
                    temp->next->prev = current;
                    // it is not the last node, need to connect the next node (alr skipped deleted node)
                    //back to the current, which is the 
                    // previous of temp (deleted node)
                }
                delete temp; 
                return;
            }
            current = current->next; //keep looping to find the matching name
        }
    }
    
    //display the linked list
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }

    void displayReverse() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        // go to the last node first 
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next; 
        }

        // displaying the node of current and this current will keep referring back when back has node
        while (current != nullptr) {
            cout << current->name; 
            current = current->prev;
            cout << endl;
        } 
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "\nInitial list:" << endl;
    list.display();

    cout << "\nAfter inserting Ali after Anjana:" << endl;
    list.insertAfter("Anjana","Ali");
    list.display();

    // insert Jane at the end
    cout << "\nAfter inserting Jane at the end:" << endl;
    list.insertEnd("Jane");
    list.display();    

    // delete Jessy
    cout << "\nAfter deleting Jessy:" << endl;
    list.deleteByName("Jessy");
    list.display();

    cout << "\nReverse linkedlist:" << endl;
    list.displayReverse();

    cout << "\nFinal list (in order):" << endl;
    list.display();
}