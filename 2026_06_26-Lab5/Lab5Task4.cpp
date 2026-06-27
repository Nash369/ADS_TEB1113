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
    Node(string n) {
        name = n; 
        next = nullptr;

    }
};

class Stack {
public:
    Node* top; 
    Stack() {
        top = nullptr;
    }

    void push(string name) {
        Node* newNode = new Node(name);
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (top == nullptr) {
            cout << "This stack is empty";
        }
        Node* temp = top;
        top = top->next;
        cout << endl;
        cout << temp->name << " is popped" << endl;
        delete temp;
    }

    void display() {
        Node* current = top;
        if(current == nullptr) {
            cout << "The stack is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
   Stack s;

   s.push("Aimar");
   s.push("Ahmad");
   s.push("Anjana");

   cout << "Display from top to bottom:" << endl;
   s.display();

   s.pop();
   // print the lastest stack
   cout << "\nAfter pop:" << endl;
   s.display();
}