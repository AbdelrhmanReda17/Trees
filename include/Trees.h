#ifndef TREES_H
#define TREES_H

#include <vector>
#include "Student.h"

class Tree{
  private:
    vector<Student> stds;
    string name;
  public:
    virtual void insert(Student std) = 0;
    virtual void printAll() = 0;
    virtual void search(int id)= 0;
    virtual void remove(int id)= 0;
    virtual void setStudent(vector<Student> students) = 0;
    void setName(string name);
    string getName();
};

class BST :public Tree{
public:
    BST();
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudent(vector<Student> students) override;
};
class AVL :public Tree{
public:
    AVL();
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudent(vector<Student> students) override;
};
class Min_Heap :public Tree{
public:
    Min_Heap();
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudent(vector<Student> students) override;
};
class Max_Heap :public Tree{
public:
    Max_Heap();
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudent(vector<Student> students) override;
};

#endif
