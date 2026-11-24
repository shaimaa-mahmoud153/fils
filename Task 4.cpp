#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    cout << "Enter how many persons: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of persons must be greater than 0." << endl;
        return 1;
    }

    ofstream outFile("C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\persons.txt");
    if (!outFile.is_open()) {
        cout << "Error opening persons.txt for writing!" << endl;
        return 1;
    }

    for (int i = 0; i < n; i++) {
        Person p;
        cout << "Enter person " << (i + 1) << " name: ";
        cin >> p.name;
        cout << "Enter person " << (i + 1) << " age: ";
        cin >> p.age;
        outFile << p.name << " " << p.age << endl;
    }
    outFile.close();

    ifstream inFile("C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\persons.txt");
    if (!inFile.is_open()) {
        cout << "Error opening persons.txt for reading!" << endl;
        return 1;
    }

    vector<Person> persons;
    Person temp;
    while (inFile >> temp.name >> temp.age) {
        persons.push_back(temp);
    }
    inFile.close();

    Person younger = persons[0];
    Person older = persons[0];

    for (size_t i = 1; i < persons.size(); i++) {
        if (persons[i].age < younger.age) younger = persons[i];
        if (persons[i].age > older.age) older = persons[i];
    }

    ofstream resFile("C:\\Users\\TESTSYS\\Desktop\\New folder (3)\\file\\results.txt");
    resFile << "Younger person: " << younger.name << " (" << younger.age << ")" << endl;
    resFile << "Older person: " << older.name << " (" << older.age << ")" << endl;
    resFile.close();

    cout << "\nDone! Younger: " << younger.name << " (" << younger.age << ")" << endl;
    cout << "Older: " << older.name << " (" << older.age << ")" << endl;
    return 0;
}
