#include <iostream>
using namespace std;
// pass by reference
// THIS PROGRAM DOESN'T 
int two_parameter_sequence(int &a, int &b, int &sum){
    if (a == 0){
        if (b == 0){
            sum += 1;
        } else {
            sum += b;
            sum += two_parameter_sequence(1,b-1,sum);
        }
    } else {
        if (b == 0){
            sum += a;
            int x = a;
            sum += two_parameter_sequence(x-1,1,sum);
        } else {
            sum += a;
            sum += two_parameter_sequence(a-1,b-1,sum);
        }
    }
    return sum;
}
int main(){
    cout << "The value of the sequence with input (5,3) is: " << two_parameter_sequence(5,3,0);
}