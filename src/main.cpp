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
//functions 
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

    if (!readGradeData(filename, students, numStudents, numTests)){
        cerr << "Error: failed to process file." << endl;
        return 1;
    }
    // calculate averages and assign letter grades
    processGrades(students, numStudents, numTests);
    //dispay report
    displayReport(students, numStudents, numTests);
    //release dynamic memory
    releaseMemory( students, numStudents);


    return 0;
}
bool readGradeData(const string& filename, Student*& students, int& numStudents, int& numTest) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: could not open file" << filename << endl;
        return false;
    }

    //outer array
}