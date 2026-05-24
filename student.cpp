#include "student.h"
#include <iostream>
#include <fstream>

using namespace std;

void Add_Student(vector<Student> &students)
{
    ofstream StudentFile("students.txt", ios::app);
    Student st;
    cout << "Enter your name: ";
    getline(cin, st.name);
    cout << "Enter your ID: ";
    cin >> st.id;

    StudentFile << st.name << endl
                << st.id << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter grade for course " << i + 1 << ": ";
        cin >> st.grade[i];
        StudentFile << st.grade[i] << " ";
    }
    StudentFile << endl;
    StudentFile.close();
    students.push_back(st);
}

void View_Student(vector<Student> &students)
{

    if (students.empty())
    {
        cout << "No students Found.\n";
    }

    else
    {
        for (int i = 0; i < students.size(); i++)
        {
            cout << "Student# " << i + 1 << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Grades: ";
            for (int j = 0; j < 5; j++)
            {
                cout << students[i].grade[j] << " ";
            }
            cout << endl;

            cout << "-------------------------" << endl;
        }
    }
}

void Search_Student(vector<Student> &students)
{
    int search_ID;
    cout << "Enter your ID: \n";
    cin >> search_ID;

    bool found = false;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].id == search_ID)
        {
            cout << "Student# " << i + 1 << endl;
            cout << "Name: " << students[i].name << endl;
            cout << "ID: " << students[i].id << endl;
            cout << "Grades: ";
            for (int j = 0; j < 5; j++)
            {
                cout << students[i].grade[j] << " ";
            }
            cout << endl;

            cout << "-------------------------" << endl;

            found = true;
        }
    }
    if (!found)
    {
        cout << "Student not found.\n";
    }
}

void CalculateGrade(vector<Student> &students)
{
    int choice;
    cout << "Calculate Grades Menu:\n";
    cout << "1.Average\n";
    cout << "2.Maximum grade\n";
    cout << "3.GPA\n";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Calculate_Average(students);
        break;
    case 2:
        Calculate_Maximum(students);
        break;
    }
}

void Calculate_Average(vector<Student> &students)
{
    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].id == searchID)
        {
            double sum = 0;
            for (int j = 0; j < 5; j++)
            {
                sum += students[i].grade[j];
            }

            double Avg = sum / 5;
            cout << "Average Grade for student " << students[i].name << ": " << Avg << endl;
        }
    }
}
void Calculate_Maximum(vector<Student> &students)
{
    int searchID;
    cout << "Enter student ID: ";
    cin >> searchID;

    for (int i = 0; i < students.size(); i++)
    {

        if (students[i].id == searchID)
        {
            double max = students[i].grade[0];
            for (int j = 1; j < 5; j++)
            {
                if (students[i].grade[j] > max)
                {
                    max = students[i].grade[j];
                }
            }

            cout << "The maximum Grade for student " << max;
        }
    }
}
