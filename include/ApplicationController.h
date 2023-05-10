#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <vector>
#include "Student.h"
#include "trees.h"
class ApplicationController {
private:
    std::vector<Student> stds;
    Tree* ts = nullptr;
    Heap* hp = nullptr;
    string file;
public:
    void GetStudents();
    void StartApplication(string file);
    void setStudents(std::vector<Student> stds);
    void MainMenu();
    void AlternativeMenu(bool isAVLBST);
};

#endif
