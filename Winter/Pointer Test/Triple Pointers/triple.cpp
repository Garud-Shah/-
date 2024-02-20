#include <iostream>
using namespace std;
int main() {
    freopen("help.txt","w",stdout);
    cout << "int ptr0 = 10;" << endl;
    for (int i = 1; i < 10000; i++){
        cout << "int ";
        for (int j = 0; j<i; j++){
            cout << "*";
            
        }
        cout << "ptr" << i << " = &ptr" << i-1 << ";" << endl;
        cout << "cout << ptr" << i << " << endl" << "; \n";
    }
    return 0;
}
