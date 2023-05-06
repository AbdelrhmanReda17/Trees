#include "../include/Student.h"

int Student::getID() {
    return id;
}

void Student::setID(int id) {
    this->id = id;
}

std::string Student::getName() {
    return name;
}

void Student::setName(std::string name) {
    this->name = name;
}

float Student::getGPA() {
    return gpa;
}

void Student::setGPA(float gpa) {
    this->gpa = gpa;
}

std::string Student::getDepartment() {
    return department;
}

void Student::setDepartment(std::string department) {
    this->department = department;
}
void Student::print(){
    cout << "[ " << getID() << ", " << getName() << ", " << getGPA() << ", "<< getDepartment() << "]" << endl;

}
void Student::addinfo(){
    cout << "Enter the id:";
    int id ; cin >> id ; this->id = id;
    cout << "Enter the name:";
    string name ; cin >> name ; this->name = name;
    cout << "Enter the gpa:";
    float gpa ; cin >> gpa ; this->gpa = gpa;    
    cout << "Enter the department:";
    string department ; cin >> department ; this->department = department;
}