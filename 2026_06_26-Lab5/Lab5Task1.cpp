/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Queue {
public:
    string arr[100]; //fixed size
    int front;
    int rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    void enqueue(string name) {
        //check is the queue is full
        if (rear == 100) {
            cout << "The queue is full." << endl;
            return;
        }

        //check if this is the first element
        if (front == 0) {
            front = 1;
        }
        //move the front first

        //later here we move the rear here
        rear++;
        arr[rear] = name;
    }

    void dequeue() {
        if (front == 0) {
            cout << "This queue is empty";
            return;
        }
        cout << endl;
        cout << arr[front] << " is dequeued." << endl;
        front++;

        // check if this is the last element (which alr deleted)
        if(front > rear) {
            front = rear = -1; 
        }
    }

    void display() {
        if (front == 0) {
            cout << "This queue is empty";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
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