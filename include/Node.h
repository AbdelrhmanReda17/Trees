#ifndef NODE_H
#define NODE_H
#include "Student.h"
using namespace std;

class Node{
public:
    Student* student;
    Node *left;
    Node *right;
    Node(Student* student){
        this->student=student;
        left=right=NULL;
    }
};

#endif
