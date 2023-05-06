#include<bits/stdc++.h>
#include "../include/Trees.h"
#include "../include/Student.h"
#include "../include/Node.h"

using namespace std;
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Tree ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
vector<Student> Tree::getStudents(){
    return stds;
}
void Tree::setName(string name){
    this->name = name;
}
string Tree::getName(){
    return name;
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- BST ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
BST::BST(vector<Student> stds){
    Tree::setName("BST");
    setStudents(stds);
}
//  Insert A Studnet 
void BST::insert(Student std) {
    root = insertUtil(root , std);
}
Node* BST::insertUtil(Node* node, Student std) {
    if (node == NULL) {
        return new Node(std);
    }
    if (std.getID() <= node->student.getID()) {
        node->left = insertUtil(node->left, std);
    } else if (std.getID() > node->student.getID()) {
        node->right = insertUtil(node->right, std);
    }
    return node;
}
//  Print All Studnet 
void BST::printAll() {
    cout << "------------------------------------------------------------------------\n";
    map<string , int> mp;
    if (root == NULL) {
        cout << "The tree is empty" << endl;
        return;
    }
    cout << "Students sorted by ID: " << endl;
    printAllUtil(root , mp);
    cout << "Students per Departments:" << endl;
    for(auto it : mp){
        cout << it.first << " "<< it.second << " Students" << endl;
    }
    cout << "------------------------------------------------------------------------\n";
}
void BST::printAllUtil(Node* node, map<string , int>& mp) {
        if (node == NULL) {
            return;
        }
        printAllUtil(node->left , mp);
        mp[node->student.getDepartment()]++; // add student record to map
        node->student.print();
        printAllUtil(node->right , mp);
}
void BST::search(int id) {
    Node* node = searchUtil(root , id);
    if(node == NULL){
        cout << "Student not found\n";
    }else{
        cout << "Student is found\n";
        node->student.print();
    }
}
Node* BST::searchUtil(Node* node,int id) {
    if(node == NULL) {
        return NULL;
    }
    if(node->student.getID() == id) {
        return node;
    } else if (node->student.getID() < id) {
        return searchUtil(node->right, id);
    } else {
        return searchUtil(node->left, id);
    }
}

void BST::remove(int id) {
    Node* node = searchUtil(root, id);
    if(node != NULL) {
        cout << "Student is found\n";
        node->student.print();
        root = removeUtil(root, id);
        cout << "Student Deleted\n";
    }else {
        cout << "Student not found\n";
    }
}
Node* BST::removeUtil(Node* node, int id) {
    if(node == NULL) return NULL;

    if(id < node->student.getID()) {
        node->left = removeUtil(node->left, id);
    } else if(id > node->student.getID()) {
        node->right = removeUtil(node->right, id);
    } else {
        if(node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if(node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* current = node->right;
            while(current && current->left != NULL) {
                current = current->left;
            }
            node->student = current->student;
            node->right = removeUtil(node->right, current->student.getID());
        }
    }
    return node;
}

void BST::setStudents(vector<Student> students) {
    for(int i = 0 ; i < students.size() ; i++){
            BST::insert(students[i]);
    }
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- AVL ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
AVL::AVL(vector<Student> stds){
    Tree::setName("AVL");
    setStudents(stds);
}
void AVL::insert(Student std) {
    cout << "Inserting a node in the AVL\n";
}


void AVL::printAll() {
    cout << "Print all nodes in the AVL\n";
}

void AVL::search(int id) {
    cout << "Searching for node in the AVL\n";

}

void AVL::remove(int id) {
    cout << "Remove a node in the AVL\n";
}

void AVL::setStudents(vector<Student> students) {
    for(int i = 0 ; i < students.size() ; i++){
        insert(students[i]);
    }
}

//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Min_Heap -------------------------------------------------
//----------------------------------------------------------------------------------------------------------
Min_Heap::Min_Heap(vector<Student> stds){
    Tree::setName("Min_Heap");
    setStudents(stds);
}
void Min_Heap::insert(Student std) {
    cout << "Inserting a node in the Min_Heap\n";
}


void Min_Heap::printAll() {
    cout << "Print all nodes in the Min_Heap\n";
}

void Min_Heap::search(int id) {}

void Min_Heap::remove(int id) {}

void Min_Heap::setStudents(vector<Student> students) {
    for(int i = 0 ; i < students.size() ; i++){
        insert(students[i]);
    }
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Max_Heap -------------------------------------------------
//----------------------------------------------------------------------------------------------------------
Max_Heap::Max_Heap(vector<Student> stds){
    Tree::setName("Max_Heap");
    setStudents(stds);
}
void Max_Heap::insert(Student std) {
    cout << "Inserting a node in the Max_Heap\n";
}


void Max_Heap::printAll() {
    cout << "Print all nodes in the Max_Heap\n";
}

void Max_Heap::search(int id) {}
void Max_Heap::remove(int id) {}
void Max_Heap::setStudents(vector<Student> students) {
    for(int i = 0 ; i < students.size() ; i++){
        insert(students[i]);
    }
}
//----------------------------------------------------------------------------------------------------------
