#ifndef TREES_H
#define TREES_H

#include <vector>
#include <map>
#include "Student.h"
#include "Node.h"

class Heap{  
  protected:
    int parent(int i);
    int leftChild(int i);
    int rightChild(int i);
    void setStudents(vector<Student> stds);
    vector<Student> stds;    
  private:
    string name;
  public:
    virtual void insert(Student std) = 0;
    virtual void heapSort(int n) = 0;
    virtual void printAll() = 0;
};
class Min_Heap :public Heap{
private:
    void Heapfiy(int n ,int i);
public:
    Min_Heap(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void heapSort(int n) override;
};
class Max_Heap :public Heap{
private:
    void Heapfiy(int n ,int i);
public:
    Max_Heap(vector<Student>);
    void insert(Student std) override;
    void heapSort(int n) override;
    void printAll() override;
};

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
        Node* insertUtil(Node* node, Student std);
        void printAllUtil(Node* node , map<string , int>& mp) ;
        Node* searchUtil(Node* node,int id) ;
        Node* removeUtil(Node* node, int id);
        Node* rightRotate(Node* node);
        Node* leftRotate(Node* node);
        int getHeight(Node* node);
        int getBalance(Node* node);
public:
    Node* root = NULL;
    AVL(vector<Student>);
    void insert(Student std) override;
    void printAll() override;
    void search(int id) override;
    void remove(int id) override;
    void setStudents(vector<Student> students) override;
};


#endif
