// this is a call by pointer implementation
#include <iostream>
using namespace std;
void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main(){
    int x, y; 
    cout << "Enter the first number: ";
    cin >> x;
    cout << "Enter the second number: ";
    cin >> y;
    swap(&x,&y);
    cout << "Swapped: " << x << " " << y;
}