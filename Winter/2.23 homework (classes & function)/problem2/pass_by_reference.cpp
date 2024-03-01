#include <iostream>
using namespace std;
// pass by reference
// THIS PROGRAM DOESN'T 
int two_parameter_sequence(int &a, int &b, int &sum){
    if ((a+b) == 1){
        return 2;
    }
    if (a == 0){
        if (b == 0){
            sum += 1;
        } else {
            sum += b;
            a++; b--;
            sum += two_parameter_sequence(a,b,sum);
        }
    } else {
        if (b == 0){
            sum += a;
            a--; b++;
            sum += two_parameter_sequence(a,b,sum);
        } else {
            sum += a;
            a--; b--;
            sum += two_parameter_sequence(a,b,sum);
        }
    }
    return sum;
}
int main(){
    cout << "The value of the sequence with input (5,3) is: " << two_parameter_sequence(5,3,0);
}