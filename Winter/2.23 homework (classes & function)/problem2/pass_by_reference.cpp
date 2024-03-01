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
    // yes i used the call limits I found using binary search last time
    int a = 174687; int b = 174685; int sum = 0;
    cout << "STRESS TEST: " << two_parameter_sequence(a,b,sum);
}