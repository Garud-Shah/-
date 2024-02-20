#include <iostream>
#include <string>
using namespace std;
int main(){
    int* vptr;
    int** dptr;
    int*** tptr;
    int var = 10;
    vptr = &var;
    dptr = &vptr;
    tptr = &dptr;
    cout << "Intial: " << var << endl;
    cout << "1 ptr: " << *vptr << endl;
    cout << "1 ptr adress: " << vptr << endl;
    cout << "2 ptr: " << **dptr << endl;
    cout << "2 ptr adress: " << dptr << endl;
    cout << "3 ptr: " << ***tptr << endl;
    cout << "3 ptr adress: " << tptr << endl;
}