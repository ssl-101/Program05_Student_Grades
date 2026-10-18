#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

struct Student {
    string lastName;
    int studentID;
    double* scores;
    double average;
    char letterGrade;
};

bool readGradeData (const string& filename, Student*& students, int& numStudents, int& numTests);
void processGrades (Student* students, int numStudents, int numTests);
void displayReport (const Student* students, int numStudents, int numTest);
void releaseMemory (Student*& students, int numStudents);

int main() {
    string filename;
    cout << "student_data.txt";
    cin >> filename;

    Student* students = nullptr;
    int numStudents = 0;
    int numTests = 0;

}