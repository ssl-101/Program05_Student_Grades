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
void displayReport (const Student* students, int numStudents, int numTests);
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
bool readGradeData(const string& filename, Student*& students, int& numStudents, int& numTests) {
    ifstream inFile(filename);
    if (!inFile.is_open()) {
        cerr << "Error: could not open file" << filename << endl;
        return false;
    }
    inFile >> numStudents >> numTests;
    if (numStudents <= 0 || numTests <=0) {
        cerr << "Error: Invalid header, must be a positive number." << endl;
        inFile.close();
        return false;
    }

    //outer array
    students = new Student[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        inFile >> students[i].lastName >> students[i].studentID;

        // inner array for score
        students[i].scores = new double[numTests];
        for (int j = 0; j < numTests; ++j) {
            inFile >> students[i].scores[j];
        }
    }
    
    inFile.close();
    return true;
} 

// calculating averages and assigne letter grades in one loop
void processGrades (Student* students, int numStudents, int numTests) {
     for (int i = 0; i < numStudents; ++i) {
         double sum = 0.0;
         for (int j = 0; j < numTests; ++j) { 
             sum += students[i]. scores [j];
         }
      // Calculate average
      students[i].average = (numTests > 0) ? (sum / numTests) : 0.0;
     // Assign letter grade 
     double avg = students[i]. average;
     if (avg >= 90.0) students[i].letterGrade = 'A';
     else if (avg >= 80.0) students[i].letterGrade = 'B';
     else if (avg >= 70.0) students[i].letterGrade = 'C';
     else if (avg >= 60.0) students[i].letterGrade = 'D';
     else students[i].letterGrade = 'F';
  }
}