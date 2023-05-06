#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <vector>
#include "Student.h"
#include "trees.h"
class ApplicationController {
private:
    std::vector<Student> stds;
    Tree* ts = nullptr;

public:
    void GetStudents(int n);
    void StartApplication();
    void setStudents(std::vector<Student> stds);
    void MainMenu();
    void AlternativeMenu();
};

#endif
