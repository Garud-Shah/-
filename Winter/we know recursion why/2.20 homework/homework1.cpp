#include <iostream>
#include <chrono>
using namespace std;
double time_in_seconds() {
    using namespace std::chrono;
    return duration_cast<microseconds>(system_clock::now().time_since_epoch()).count() / 1000000.0;
}
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
    // float time = time_in_seconds();
    unsigned int test = 174687; 
    /* 174688 fails, this is the highest value where we don't have too many stack calls! 
    (btw if I didn't have this protection I would have erased my RAM and have to restart my computer) */ 
    cout << "Sum up to 32-bit unsigned integer limit is: " << closeform(test);
    cout << "\nThis will not run for x>~100 but it's a check:  " << sum(test);
}