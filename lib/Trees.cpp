#include<bits/stdc++.h>
#include "../include/Trees.h"
#include "../include/Student.h"

using namespace std;
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Tree ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
void Tree::setName(string name){
    this->name = name;
}
string Tree::getName(){
    return name;
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- BST ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
BST::BST(){
    Tree::setName("BST");
}
void BST::insert(Student std) {
    cout << "Inserting a node in the BST\n";
}


void BST::printAll() {
    cout << "Print all nodes in the BST\n";
}

void BST::search(int id) {
    cout << "Searching for node in the BST\n";

}

void BST::remove(int id) {
    cout << "Remove a node in the BST\n";

}

void BST::setStudent(vector<Student> students) {
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- AVL ------------------------------------------------------
//----------------------------------------------------------------------------------------------------------
AVL::AVL(){
    Tree::setName("AVL");
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

void AVL::setStudent(vector<Student> students) {
}

//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Min_Heap -------------------------------------------------
//----------------------------------------------------------------------------------------------------------
Min_Heap::Min_Heap(){
    Tree::setName("Min_Heap");
}
void Min_Heap::insert(Student std) {
    cout << "Inserting a node in the Min_Heap\n";
}


void Min_Heap::printAll() {
    cout << "Print all nodes in the Min_Heap\n";
}

void Min_Heap::search(int id) {}

void Min_Heap::remove(int id) {}

void Min_Heap::setStudent(vector<Student> students) {
}
//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Max_Heap -------------------------------------------------
//----------------------------------------------------------------------------------------------------------
Max_Heap::Max_Heap(){
    Tree::setName("Max_Heap");
}
void Max_Heap::insert(Student std) {
    cout << "Inserting a node in the Max_Heap\n";
}


void Max_Heap::printAll() {
    cout << "Print all nodes in the Max_Heap\n";
}

void Max_Heap::search(int id) {}
void Max_Heap::remove(int id) {}
void Max_Heap::setStudent(vector<Student> students) {}
//----------------------------------------------------------------------------------------------------------
