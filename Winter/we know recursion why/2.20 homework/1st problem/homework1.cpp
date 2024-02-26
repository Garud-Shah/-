#include <iostream>
using namespace std;
// time complexity is S(a) = O(k) + S(n-k) -> O(a) + O(1) -> O(a).
unsigned long long int sum(unsigned long long int a){
    if (a <= 0){
        return 0;
    } else {
        unsigned long long int previous = sum(a-1);
        unsigned long long int sum = previous + a;
        return sum;
    }
}
// IT'S O(1) - EVEN FOR MEMORY! (why it's so important to have a closed form)
unsigned long long int closeform(unsigned long long int a){
    unsigned long long int out = a * (a+1) / 2;
    return out;
}
int main(){
    unsigned int test = 174687; 
    /* 174688 fails, this is the highest value where we don't have too many stack calls! 
    By the way, if I didn't have this protection I would have erased all my working RAM and restart my computer while the code was running, 
    I was orignally putting in the 32 bit unsigned integer limit by using hexadecimal (0xFFFFFFFF). */ 
    cout << "Sum up to 32-bit unsigned integer limit is: " << closeform(test);
    cout << "\nThis will not run for x>~100 but it's a check:  " << sum(test);
}