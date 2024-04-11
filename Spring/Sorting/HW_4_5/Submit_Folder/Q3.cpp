#include <iostream>
#include <cmath>
using namespace std;
struct number {
    float decimal;
    int intpart;
    float fracpart;
};
int main(){
    number mynumber;
    cout << "Enter a number: "; cin >> mynumber.decimal;
    mynumber.intpart = mynumber.decimal;
    mynumber.fracpart = mynumber.decimal - mynumber.intpart;
    cout << "Its fractional part is " << mynumber.fracpart << endl;
    cout << "Its integer part is " << mynumber.intpart << endl;
}