#include <iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
   string name;
   int id;
   int grade;

    cout << "Enter student name:";
    getline(cin,name);


     cout <<"Enter student id :";
     cin >>id;

     cout <<"Enter student grade :";
     cin >>grade;

    ofstream myfile("student.txt")  ;

    myfile <<"Name:"<<name<< endl;
     myfile <<"ID:"<<id<< endl;
      myfile <<"Grade:"<<grade<< endl;

     myfile.close();

    return 0;
}
