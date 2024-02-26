#include <iostream>
using namespace std;
// When calling the function is the LAST step, it is TAIL recursion.
void function(int n){
    if (n > 0){
        cout << n*n << endl;
        function(n-1);
    }
}
int main(){
    function(4);
}