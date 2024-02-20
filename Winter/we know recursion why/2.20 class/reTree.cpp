#include <iostream>
using namespace std;
// Tree recursion calls itself multiple times.
void function(int n){
    if (n > 0){
        function(n-1);
        cout << n*n << endl;
        function(n-1);
    }
}
int main(){
    function(4);
}