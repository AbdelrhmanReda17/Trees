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
