/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string id;
    string name;
    string course;
    int age;
};

int main() {
    Student student[5];

    student[0] = {"24007271", "Reeyan", "IT", 26};
    student[1] = {"24007272", "Aimar", "CS", 20};

    cout << "*** Student 1 ***" << endl;
    cout << "ID: " << student[0].id << endl;
    cout << "Name: " << student[0].name << endl;
    cout << "Course: " << student[0].course << endl;
    cout << "Age: " << student[0].age << endl;

    string searchID = "24007271";

    for (int i = 0; i < 5; i++) {
        if (student[i].id == searchID) {
            cout << "\nRecord Found!" << endl;
            cout << "Name: " << student[i].name << endl;
        }
    }

    for (int i = 0; i < 5; i++) {
        if (student[i].id == searchID) {
            student[i].name = "Updated Reeyan";
            break;
        }
    }

    return 0;
}