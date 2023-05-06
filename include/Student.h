#ifndef STUDENT_H
#define STUDENT_H

#include<string>
using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;
    string department;

public:
    int getID();
    void setID(int id);
    string getName();
    void setName(string name);
    float getGPA();
    void setGPA(float gpa);
    string getDepartment();
    void setDepartment(string department);
};

#endif
