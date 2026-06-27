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
    Node* next; //memory address of the next node
    //own next pointer
    // 

    // a constructor for setting up when new node is created
    Node(string n) {
        name = n; //the string will pass here to declare first
        next = nullptr;
        // so this is the Node* by default 
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
        current->next = newNode; 
        //Anjana now points to Ali 
    }

    void deleteByName (string name) {
        if (head == nullptr) {
            return; //empty list
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp; // if the deleted one should be head
            return;
        }
        // search the rest of the list 
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next; //using this mean assigned the address to temp
                current->next = temp->next; 
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
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

     cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana","Ali");

    // insert Jessy at the end
    list.insertEnd("Jane");

    // delete Anjana
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();
    
}