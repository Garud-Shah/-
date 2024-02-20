#include <iostream>
using namespace std;
void function(int n){
    if (n > 0){
        cout << n*n << endl;
        function(n-1);
    }
}
int main(){
    function(4);
}