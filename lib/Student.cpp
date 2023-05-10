#include "../include/Student.h"

int Student::getID() {
    return id;
}


std::string Student::getName() {
    return name;
}


double Student::getGPA() {
    return gpa;
}



std::string Student::getDepartment() {
    return department;
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