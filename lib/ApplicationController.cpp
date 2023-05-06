#include "../include/ApplicationController.h"
#include "Student.cpp"
#include "Trees.cpp"

#include <iostream>
using namespace std;
void ApplicationController::setStudents(std::vector<Student> stds) {
    this->stds = stds;
}


void ApplicationController::StartApplication() {
    std::cout << "Welcome to our X School" << std::endl;
    std::cout << "Please Enter the number of Students :" << std::endl;
    int n; std::cin >> n;
    GetStudents(n);
    MainMenu();
}
void ApplicationController::GetStudents(int n) {
    std::vector<Student> stds(n);
    int id;
    double gpa;
    std::string department, name;
    cin.ignore();
    for(int i = 0; i < n; i++) {
        std::cin >> id; stds[i].setID(id); cin.ignore();
        getline(cin , name); stds[i].setName(name);
        std::cin >> gpa; stds[i].setGPA(gpa); cin.ignore();
        getline(cin , department); stds[i].setDepartment(department);
    }
    setStudents(stds);
}
void ApplicationController::MainMenu(){
    bool isExit = false;
    while(true){
        cout << "Choose Data Structure:\n";
        cout << "1. BST\n"
                "2. AVL\n"
                "3. Min Heap\n"
                "4. Max Heap\n"
                "0. Exit:\n";
        int choose; cin >> choose;
        switch (choose)
        {
        case 1:
            ts = new BST(stds);
            break;
        case 2:
            ts = new AVL(stds);
            break;
        case 3:
            ts = new Min_Heap(stds);
            break;
        case 4:
            ts = new Max_Heap(stds);
            break;
        case 0:
            isExit = true;
            break;
        default:
            cout << "Wrong Choose , Please Enter Again\n";
            break;
        }
        if(isExit){
            cout << "Thanks";
            break;
        }else{
            AlternativeMenu();
        }
    }
}
void ApplicationController::AlternativeMenu(){
    bool isAVLBST = false , isExit = false;
    if(ts->getName() == "AVL" || ts->getName() == "BST"){
        isAVLBST = true;
    }
    Student std;
    while(true){
        cout << "Choose one of the following options:\n";
        cout << "1. Add student\n";
        cout  << (isAVLBST ? "2. Remove student\n3. Search student\n4. " : "2. ");
        cout << "Print All (sorted by id)\n"
                "0. Return to main menu:\n";
        int choose; cin >> choose;
        switch (choose)
        {
            case 1:
                std.addinfo();
                ts->insert(std);
                break;
            case 2:{
                if(isAVLBST){
                    cout << "------------------------------------------------------------------------\n";
                    cout << "Enter the id of Student :";
                    int id; cin >> id;
                    ts->remove(id);
                    cout << "------------------------------------------------------------------------\n";
                }else{
                    ts->printAll();
                }
                break;
            }
            case 3:
                if(isAVLBST)
                    {
                        cout << "------------------------------------------------------------------------\n";
                        cout << "Enter the id of Student :";
                        int id; cin >> id;
                        ts->search(id);
                        cout << "------------------------------------------------------------------------\n";
                    }
                else
                    cout << "Wrong Choose , Please Enter Again\n";
                break;
            case 4:
                if(isAVLBST)
                    ts->printAll();
                else
                    cout << "Wrong Choose , Please Enter Again\n";
                break;
            case 0:
                return;
            default:
                cout << "Wrong Choose , Please Enter Again\n";
                break;
        }
    }
}