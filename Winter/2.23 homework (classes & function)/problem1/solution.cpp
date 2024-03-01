#include <iostream>
#include <vector>
using namespace std;
struct student {
    int studentID;
    string name;
    float grade;
};
/*pseudo-random student ID/roll number generation for teachers to grade based on making it unbiased*/ 
int pseudohash(int number, int depth, int modulus){
    if (modulus == 0){
        return 1893587;
    }
    if (depth == 0){
        return number % modulus;
    } else {
        int sum = 0;
        for (int i=2; i<modulus; i++){
            sum += pseudohash(number % i, depth % i, modulus % i) % depth;
        }
        sum %= modulus;
        return sum;
    }
}
int main(){
    vector<student> students = {};
    for (int i=1; i<=5; i++){
        student current;
        int grade; string input;
        int k = i*23;
        current.studentID = pseudohash(i*i*i,k,k);
        cout << "Enter the student with ID " << current.studentID << "'s name: "; cin >> current.name;
        cout << "Enter "<< current.name << "'s grade percentage: "; cin >> current.grade;
        students.push_back(current);
    }
    int i = 2;
    int k = i*203;
    int ID = pseudohash(i*i*i,k,k);
    cout << "Details of student with ID " << ID << " are:" << endl;
    cout << "NAME: " << students[1].name << endl;
    cout << "GRADE: " << students[1].grade << endl;
    cout << "I would have implemented a private-public system for setting names and grades, but that would require classes." << endl << endl;
}