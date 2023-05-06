#ifndef TREES_H
#define TREES_H

#include <vector>
#include <map>
#include "Student.h"
#include "Node.h"

// class Node{
// public:
//     Student student;
//     Node *left;
//     Node *right;
//     Node(Student student){
//         this->student=student;
//         left=right=NULL;
//     }
// };

class Tree{
  private:
    vector<Student> stds;
    string name;
  public:
    virtual void insert(Student std) = 0;
    virtual void printAll() = 0;
    virtual void search(int id)= 0;
    virtual void remove(int id)= 0;
    virtual void setStudents(vector<Student> students) = 0;
    virtual vector<Student> getStudents();
    void setName(string name);
    string getName();
};

class BST :public Tree{
private : 
        Node* insertUtil(Node* node, Student std);
        void printAllUtil(Node* node , map<string , int>& mp) ;
        Node* searchUtil(Node* node,int id) ;
        Node* removeUtil(Node* node, int id);

public:
    Node* root = NULL;
    BST(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudents(vector<Student> students) override;
};
class AVL :public Tree{
public:
    AVL(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudents(vector<Student> students) override;
};
class Min_Heap :public Tree{
public:
    Min_Heap(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudents(vector<Student> students) override;
};
class Max_Heap :public Tree{
public:
    Max_Heap(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudents(vector<Student> students) override;
};

#endif
