#include <iostream>
using namespace std;
// pass by reference
// im too lazy to implement a dynamic programming version
int two_parameter_sequence(int a, int b, int* sum){
    if ((a+b) == 1){
        return 2;
    }
    if (a == 0){
        if (b == 0){
            *sum += 1;
        } else {
            *sum += b;
            *sum += two_parameter_sequence(a+1,b-1,sum);
        }
    } else {
        if (b == 0){
            *sum += a;
            *sum += two_parameter_sequence(a-1,b+1,sum);
        } else {            
            *sum += a;
            *sum += two_parameter_sequence(a-1,b-1,sum);
        }
    }
    return *sum;
}
int main(){
    // pointer setup
    int sum = 0;
    int* sumptr = &sum;
    cout << "STRESS TEST: " << two_parameter_sequence(174687,174685,sumptr);
}