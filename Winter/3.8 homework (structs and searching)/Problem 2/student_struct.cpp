#include <cstdlib> 
#include <iostream> 
#include <time.h> 
using namespace std;
struct student{
    string name;
    int studentID;
    string math_grade;
    string science_grade;
    string humanitites_grade;
}
int main(){
    srand(time(0)); 
    vector<student> list = {};
    int number_of_students; cout << "How many students in the school? "; cin >> number_of_students;
    for (int i=0; i < number_of_students; i++){
        student current;
        current.studentID = rand();
        cout << "Student ID: " << current.studentID << endl << "Name of a student: ";
        cin >> current.name;
        cout << "Enter " << current.name <<"'s math grade (Letter + Specifier): "; cin >> current.math_grade;
        cout << "Enter " << current.name <<"'s science grade (Letter + Specifier): "; cin >> current.science_grade;
        cout << "Enter " << current.name <<"'s humanitites grade (Letter + Specifier): "; cin >> current.humanitites_grade;
    }
    cout << "Process completed. ";
}