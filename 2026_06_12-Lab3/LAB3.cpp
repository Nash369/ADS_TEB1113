/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next = NULL;
};

int main() {
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    Node* node5 = new Node();

    node1->name = "Aiman";
    node2->name = "Ahmad";
    node3->name = "Anajana";
    node4->name = "Jessy";
    node5->name = "Ali";

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = NULL;

    Node* display_node = node1;

    while (display_node != NULL) {
        cout << display_node->name << endl;
        display_node = display_node->next;
    }

    return 0;
}