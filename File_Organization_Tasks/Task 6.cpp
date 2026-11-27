#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int main() {

    ofstream outFile("grades.txt");
    if (!outFile) {
        cerr << "Error: Could not create grades.txt!" << endl;
        return 1;
    }

    int initialGrades[5] = {85, 92, 78, 90, 88};
    for (int i = 0; i < 5; i++) {
        outFile << initialGrades[i] << endl;
    }
    outFile.close();


    ifstream inFile("grades.txt");
    if (!inFile) {
        cerr << "Error: Could not open grades.txt for reading!" << endl;
        return 1;
    }

    cout << "Current grades in file:" << endl;
    int grade;
    while (inFile >> grade) {
        cout << grade << endl;
    }
    inFile.close();


    int gradeToDelete;
    cout << "\nEnter a grade to delete: ";
    cin >> gradeToDelete;

    ifstream sourceFile("grades.txt");
    ofstream tempFile("temp.txt");

    if (!sourceFile || !tempFile) {
        cerr << "Error: Could not open files for deletion process!" << endl;
        return 1;
    }

    bool found = false;
    while (sourceFile >> grade) {
        if (grade != gradeToDelete) {
            tempFile << grade << endl;
        } else {
            found = true;
        }
    }

    sourceFile.close();
    tempFile.close();


    if (remove("grades.txt") != 0) {
        cerr << "Error: Failed to remove the original file!" << endl;
        return 1;
    }

    if (rename("temp.txt", "grades.txt") != 0) {
        cerr << "Error: Failed to rename the temporary file!" << endl;
        return 1;
    }

    if (found) {
        cout << "Success: Grade " << gradeToDelete << " has been deleted and grades.txt is updated." << endl;
    } else {
        cout << "Notice: Grade " << gradeToDelete << " was not found, file remains unchanged." << endl;
    }


    ifstream updatedFile("grades.txt");
    if (updatedFile) {
        cout << "\nGrades after deletion:" << endl;
        while (updatedFile >> grade) {
            cout << grade << endl;
        }
        updatedFile.close();
    }

    return 0;
}
