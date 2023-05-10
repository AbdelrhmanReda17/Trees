#include "../include/ApplicationController.h"
#include "Student.cpp"
#include "Trees.cpp"

#include <iostream>
using namespace std;
void ApplicationController::setStudents(std::vector<Student> stds) {
    this->stds = stds;
}


void ApplicationController::StartApplication(string file) {
    this->file = file;
    std::cout << "Welcome to our X School" << std::endl;
    GetStudents();
    MainMenu();
}
void ApplicationController::GetStudents() {
    std::vector<Student> stds;
    ifstream infile(file);
        int numStudents;
        infile>>numStudents;
        infile.ignore(); // skip the newline character
        for (int i = 0; i < numStudents; i++) {
            int id;
            string name, major;
            double gpa;
            infile >> id;
            infile.ignore(); // skip the space character
            getline(infile, name);
            infile >> gpa >> major;
            infile.ignore(); // skip the newline character
            Student student(name, id, gpa, major);
            stds.push_back(student);
        }
    infile.close();
    setStudents(stds);
}
void ApplicationController::MainMenu(){
    bool isExit = false , isAVLBST =false;
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
            isAVLBST=true;
            break;
        case 2:
            ts = new AVL(stds);
            isAVLBST=true;
            break;
        case 3:
            hp = new Min_Heap(stds);
            isAVLBST=false;
            break;
        case 4:
            hp = new Max_Heap(stds);
            isAVLBST=false;
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
            AlternativeMenu(isAVLBST);
        }
    }
}
void ApplicationController::AlternativeMenu(bool isAVLBST){
    Student std;
    while(true){
        cout << "Choose one of the following options:\n";
        cout << "1. Add student\n";
        cout  << (isAVLBST ? "2. Remove student\n3. Search student\n4. " : "2. ");
        cout << "Print All [ORDERED]\n"
                "0. Return to main menu:\n";
        int choose; cin >> choose;
        switch (choose)
        {
            case 1:
                std.addinfo();
                if(isAVLBST)
                    ts->insert(std);
                else
                    hp->insert(std);
                break;
            case 2:{
                if(isAVLBST){
                    cout << "------------------------------------------------------------------------\n";
                    cout << "Enter the id of Student :";
                    int id; cin >> id;
                    ts->remove(id);
                    cout << "------------------------------------------------------------------------\n";
                }else{
                    hp->printAll();
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