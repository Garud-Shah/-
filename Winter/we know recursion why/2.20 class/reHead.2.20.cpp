#include <iostream>
using namespace std;
// We call the function before performing recursion here. This is head recursion.
void function(int n){
    if (n > 0){
        function(n-1);
        cout << n*n << endl;
    }
}
int main(){
    function(4);
}