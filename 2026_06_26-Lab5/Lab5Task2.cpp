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
        name = n; //the string will pass here to declare first
        next = nullptr;
    }
};

class Queue {
public:
    Node* front; 
    Node* rear;


    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(string name) {
        Node* newNode = new Node(name);
        if (rear == nullptr) {
            front = rear = newNode; //move both to one step out
            return;
        }
        rear->next = newNode; 
        rear = newNode; 
    }

    void dequeue() {
        if (front == nullptr) {
            cout << "This queue is empty";
            return;
        }
        Node* temp = front;
        front = front->next; 
        cout << endl;
        cout << temp->name << " is popped" << endl;
        delete temp;
        if(front == nullptr) {
            rear = nullptr; 
        } 
    }

    void display() {
        Node* current = front;
        if(current == nullptr) {
            cout << "The queue is empty" << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
   Queue q;

   q.enqueue("Aimar");
   q.enqueue("Ahmad");
   q.enqueue("Anjana");

   cout << "Display from front to rear (left to right):" << endl;
   q.display();

   q.dequeue();
   // print the lastest stack
   cout << "\nAfter dequeue the front:" << endl;
   q.display();
}