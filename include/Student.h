#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student {
private:
    int id;
    string name;
    double gpa;
    string department;

public:
    Student(){}
    int getID();
    string getName();
    Student(string name, int id, double gpa, string department){
        this->name=name;
        this->id=id;
        this->department=department;
        this->gpa=gpa;
    }
    double getGPA();
    string getDepartment();
    void addinfo();
    void print();
};

#endif
