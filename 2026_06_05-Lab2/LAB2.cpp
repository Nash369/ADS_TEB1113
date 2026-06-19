/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

struct Student{
    string id;
    string name;
    string course;
    int age;
};

int main() {
    Student student[1000];
    
    student[0].id = "24007271";
    student[0].name = "Reeyan";
    student[0].course = "IT";
    student[0].age = 25;
    
    student[1].id = "24006565";
    student[1].name = "Aimar";
    student[1].course = "IT";
    student[1].age = 20;
    
    cout << student[0].id << endl;
    cout << student[0].name << endl;
    cout << student[0].course << endl;
    cout << student[0].age << endl;
    
    cout << endl;
    
    cout << student[1].id << endl;
    cout << student[1].name << endl;
    cout << student[1].course << endl;
    cout << student[1].age << endl;

    return 0;
}