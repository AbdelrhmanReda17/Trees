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
void Heap::setStudents(vector<Student> stds){
    this->stds = stds;
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
    root = insertUtil(root , std);
}
int AVL::getHeight(Node* node){
    if(node == NULL){
        return -1;
    }
    return node->height;
}
int AVL::getBalance(Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return getHeight(node->left) - getHeight(node->right);
}
Node* AVL::insertUtil(Node* node, Student std){
    if (node == NULL) {
        return new Node(std);
    }
    if (std.getID() <= node->student.getID()) {
        node->left = insertUtil(node->left, std);
    } else if (std.getID() > node->student.getID()) {
        node->right = insertUtil(node->right, std);
    }
    node->height =  1 + max(getHeight(node->left) , getHeight(node->right));
    int treeBalance = getBalance(node);
     if (treeBalance > 1 && std.getID() < node->left->student.getID()) {
        return rightRotate(node);
    }

    if (treeBalance < -1 && std.getID() > node->right->student.getID()) {
        return leftRotate(node);
    }

    if (treeBalance > 1 && std.getID() > node->left->student.getID()) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (treeBalance < -1 && std.getID() < node->right->student.getID()) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
Node* AVL::leftRotate(Node* node) {
    Node* newRoot = node->right;
    Node* temp = newRoot->left;
    newRoot->left = node;
    node->right = temp;
    node->height = 1 + max(getHeight(node->left) ,getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}
Node* AVL::rightRotate(Node* node) {
    Node* newRoot = node->left;
    Node* temp = newRoot->right;
    newRoot->right = node;
    node->left = temp;
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

void AVL::printAll() {
    cout << "------------------------------------------------------------------------\n";
    map<string , int> mp;
    if (root == NULL) {
        cout << "The tree is empty" << endl;
        return;
    }
    cout << "Students sorted by ID: " << endl;
    AVL::printAllUtil(root , mp);
    cout << "Students per Departments:" << endl;
    for(auto it : mp){
        cout << it.first << " "<< it.second << " Students" << endl;
    }
    cout << "------------------------------------------------------------------------\n";
}

void AVL::printAllUtil(Node* node, map<string , int>& mp) {    //[left][root][right]   -> Ordered
        if (node == NULL) {
            return;
        }
        AVL::printAllUtil(node->left , mp);
        mp[node->student.getDepartment()]++;
        node->student.print();
        AVL::printAllUtil(node->right , mp);

}

void AVL::search(int id) {
    Node* node = searchUtil(root , id);
    if(node == NULL){
        cout << "Student not found\n";
    }else{
        cout << "Student is found\n";
        node->student.print();
    }

}
Node* AVL::searchUtil(Node* node,int id) {
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

void AVL::remove(int id) {
    root = removeUtil(root, id);
}

Node* AVL::removeUtil(Node* node, int id) {
        if (node == NULL) {
        return NULL;
    }

    if (id < node->student.getID()) {
        node->left = removeUtil(node->left, id);
    } else if (id > node->student.getID()) {
        node->right = removeUtil(node->right, id);
    } else {
        if (node->left == NULL && node->right == NULL) {
            delete node;
            node = NULL;
        } else if (node->left == NULL) {
            Node* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == NULL) {
            Node* temp = node;
            node = node->left;
            delete temp;
        } else {
            Node* current = node->right;
            while(current && current->left != NULL) {
                current = current->left;
            }
            node->student = current->student;
            node->right = removeUtil(node->right, current->student.getID());
        }
    }

    if (node == NULL) {
        return node;
    }

    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->left) >= 0) {
        return rightRotate(node);
    }

    if (balance > 1 && getBalance(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && getBalance(node->right) <= 0) {
        return leftRotate(node);
    }

    if (balance < -1 && getBalance(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
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
    Heap::setStudents(stds);
    heapSort(stds.size());
}
void Min_Heap::insert(Student std) {
    stds.push_back(std);
    heapSort(stds.size());
}

void Min_Heap::Heapfiy(int n ,int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int smallest = i;
    if(left < n && stds[left].getGPA() < stds[smallest].getGPA()){
        smallest = left;
    }
    if(right < n && stds[right].getGPA() < stds[smallest].getGPA()){
        smallest = right;
    }
    if(smallest != i){
        swap(stds[i], stds[smallest]);
        Heapfiy(n,smallest);
    }
}
void Min_Heap::heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapfiy(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(stds[0], stds[i]);
        Heapfiy(i, 0);
    }
}
void Min_Heap::printAll(){
    map<string , int> mp;
    cout << "------------------------------------------------------------------------\n";
    cout << "Students sorted by ID: " << endl;
    for(int i = 0 ; i < stds.size() ; i++){
        stds[i].print();
        mp[stds[i].getDepartment()]++;
    }
    cout << "Students per Departments:" << endl;
    for(auto it : mp){
        cout << it.first << " "<< it.second << " Students" << endl;
    }
    cout << "------------------------------------------------------------------------\n";
}
int Heap::parent(int i) {return (i - 1) / 2; }
int Heap::leftChild(int i) { return 2 * i + 1; }
int Heap::rightChild(int i) { return 2 * i + 2; }

//----------------------------------------------------------------------------------------------------------
// ---------------------------------------------- Max_Heap -------------------------------------------------
//----------------------------------------------------------------------------------------------------------
Max_Heap::Max_Heap(vector<Student> stds){
    Heap::setStudents(stds);
    heapSort(stds.size());
}
void Max_Heap::insert(Student std) {
    stds.push_back(std);
    heapSort(stds.size());
}

void Max_Heap::Heapfiy(int n , int i){
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    if(left < n && stds[left].getGPA() > stds[largest].getGPA()){
        largest = left;
    }
    if(right < n && stds[right].getGPA() > stds[largest].getGPA()){
        largest = right;
    }
    if(largest != i){
        swap(stds[i], stds[largest]);
        Heapfiy(n , largest);
    }
}
void Max_Heap::heapSort(int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapfiy(n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(stds[0], stds[i]);
        Heapfiy(i, 0);
    }
}

void Max_Heap::printAll(){
    map<string , int> mp;
    cout << "------------------------------------------------------------------------\n";
    cout << "Students sorted by ID: " << endl;
    for(int i = stds.size() - 1 ; i >= 0 ; i--){
        stds[i].print();
        mp[stds[i].getDepartment()]++;
    }
    cout << "Students per Departments:" << endl;
    for(auto it : mp){
        cout << it.first << " "<< it.second << " Students" << endl;
    }
    cout << "------------------------------------------------------------------------\n";
}
//----------------------------------------------------------------------------------------------------------
