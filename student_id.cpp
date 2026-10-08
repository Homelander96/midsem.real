#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int registerNumber;


    Student(string n, int r) {
        name = n;
        registerNumber = r;
    }


    void display() {
        cout << "Name: " << name << endl;
        cout << "Register Number: " << registerNumber << endl;
    }
};

int main() {

    Student student1("Rahul", 101);
    Student student2("Priya", 102);


    cout << "Student 1:" << endl;
    student1.display();

    cout << "\nStudent 2:" << endl;
    student2.display();

    return 0;
}
