#include <iostream>
using namespace std;
struct freedom_length {
    int inches;
    int feet;
    int feet_mod;
}; 
int main(){
    freedom_length mylen;
    cout << "Provide a length. \nGive inches. ";
    cin >> mylen.inches;
    mylen.feet_mod = (mylen.inches - mylen.inches % 12) / 12;
    cout << "Give feet. ";
    cin >> mylen.feet;
    mylen.feet += mylen.feet_mod;
    mylen.inches %= 12;
    mylen.feet_mod = 0;
    cout << "The sum of inches and feet is: " << (mylen.inches + mylen.feet) << endl;
}