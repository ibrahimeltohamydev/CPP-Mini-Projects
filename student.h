#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>

struct Student
{
    std::string name;
    int id;
    double grade[5];
};

void Add_Student(std::vector<Student> &students);
void View_Student(std::vector<Student> &students);
void Search_Student(std::vector<Student> &students);
void CalculateGrade(std::vector<Student> &students);
void Calculate_Average(std::vector<Student> &students);
void Calculate_Maximum(std::vector<Student> &students);

#endif