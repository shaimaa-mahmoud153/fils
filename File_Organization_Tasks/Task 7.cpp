#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string filePath = "C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\names.txt";

    ofstream outFile(filePath);
    if (!outFile.is_open()) {
        cout << "Error creating names.txt!" << endl;
        return 1;
    }
    outFile << "Hadeer Mahmoud\n";
    outFile << "Youssef Ali\n";
    outFile << "Ahmed Mostafa\n";
    outFile << "Esraa Ebrahim\n";
    outFile.close();

    ifstream inFile(filePath);
    if (!inFile.is_open()) {
        cout << "Error opening names.txt!" << endl;
        return 1;
    }

    vector<string> names;
    string line;
    while (getline(inFile, line)) {
        if (!line.empty()) {
            names.push_back(line);
        }
    }
    inFile.close();

    sort(names.begin(), names.end());

    cout << "Names sorted ascending Successfully" << endl;
    for (size_t i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    ofstream sortedFile("C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\sorted_names.txt");
    for (size_t i = 0; i < names.size(); i++) {
        sortedFile << names[i] << endl;
    }
    sortedFile.close();

    return 0;
}
