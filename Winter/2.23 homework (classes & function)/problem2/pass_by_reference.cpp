#include <iostream>
using namespace std;
// pass by reference
void two_parameter_sequence(int &a, int &b, int &sum){
    if (a == 0){
        if (b == 0){
            sum += 1;
        } else {
            a--;
            sum += b;
            sum += two_parameter_sequence(a+1,b-1);
        }
    } else {
        if (b == 0){
            b++;
            sum += a;
            sum += two_parameter_sequence(a-1,b+1);
        } else {
            a--;
            sum += a;
            sum += two_parameter_sequence(a-1,b-1);
        }
    }
    return sum;
}
int main(){
    
}