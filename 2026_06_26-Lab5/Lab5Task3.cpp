/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>

using namespace std;

class Stack {
public:
    string arr[100];
    int top;

    Stack() {
        top = -1;
    }

    void push(string name) {
        if(top == 99) {
            cout << "The stack is full. " << endl;
            return;
        }
        top++;
        arr[top] = name;
    }

    void pop() {
        if (top == -1) {
            cout << "The Stack is empty. " << endl;
            return;
        }
        cout << endl;
        cout << arr[top] << " is popped" << endl;
        top--;
    }

    void display() {
        if (top == -1) {
            cout << "The Stack is empty. " << endl;
            return;
        }
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << endl;       
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
   cout << "\nAfter pop:" << endl;
   s.display();
}