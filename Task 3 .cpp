 #include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("welcome.txt");

    if (!file.is_open()) {
        cout << "Error opening the file!" << endl;
        return 1;
    }

    file << "Hello Everybody";
    file.seekp(10);
    file << "one";
    file.close();

    cout << "Done! Check welcome.txt" << endl;
    return 0;
}
