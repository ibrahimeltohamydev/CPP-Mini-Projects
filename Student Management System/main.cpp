#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

struct Student
{
    string name;
    int id;
    double grade[5];
};

void Add_Student(vector<Student> &students);
void View_Student(vector<Student> &students);
void Search_Student(vector<Student> &students);
void CalculateGrade(vector<Student> &students);
void Calculate_Average(vector<Student> &students);
void Calculate_Maximum(vector<Student> &students);
void Calculate_GPA(vector<Student> &students);

int main()
{
    vector<Student> students;
    int choice;

    char start;
    cout << "Do you want to start the program? (Y / N)?\n";
    cin >> start;
    if (start == 'Y' || start == 'y')
    {
        do
        {

            cout << "==== Welcome to Student Management System ====\n\n";
            cout << "Menue: " << endl;
            cout << "1. Add student.\n";
            cout << "2. View student.\n";
            cout << "3. Search student.\n";
            cout << "4. Calculate grade of student.\n";
            cout << "5. Delet student.\n";
            cout << "0. Exit.\n";
            cout << "Enter choice: \n";
            cin >> choice;

            switch (choice)
            {
            case 1:
                Add_Student(students);
                cout << "Student added sucssefully.\n";
                break;
            case 2:
                View_Student(students);
                break;
            case 3:
                Search_Student(students);
                break;
            case 4:
                CalculateGrade(students);
                break;
            case 5:
                break;
            case 0:
                cout << "Exited.";
                break;

            default:
                cout << "Invalid choice!\n";
                break;
            }

        } while (choice != 0);
    }

    else
    {
        cout << "Program terminated.\n";
    }

    return 0;
}
