#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main() {
    ofstream outFile("C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\students.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Error opening students.txt!" << endl;
        return 1;
    }

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        char name[20];
        int id;
        float grade;
        char delim = '$';

        cout << "Enter student name: ";
        cin.ignore();
        cin.getline(name, 20);

        cout << "Enter student ID: ";
        cin >> id;

        cout << "Enter student grade: ";
        cin >> grade;

        outFile << name << ", " << id << ", " << grade << " " << delim << "\n";

        cout << "Add another student? (y/n): ";
        cin >> choice;
    }

    outFile.close();
    cout << "\nSaved records to students.txt!" << endl;
    return 0;
}
