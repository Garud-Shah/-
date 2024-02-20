#include <iostream>
#include <string>
using namespace std;
int main(){
    int var = 10;
    char c = 'A';
    void* vptr;
    int* myptr = nullptr;
    cout << "NULL pointer value: " << myptr << endl;
    vptr = &c;
    char* charptr;
    charptr = (char*)vptr;
    cout << "Our voidptr points to " << *charptr << endl;

    int* intptr;
    vptr = &var;
    intptr = (int*)vptr;
    cout << "Our voidptr points to " << *intptr << endl;
}