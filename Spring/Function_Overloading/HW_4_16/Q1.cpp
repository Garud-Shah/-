#include <iostream>
using namespace std;
void add(int a, int b){
    cout << "The sum is: " << (a+b) << "\n";
}
void add(float a, float b){
    cout << "The sum is: " << (a+b) << "\n";
}
int main(){
    int a, b;
    float c, d;
    cout << "Enter 2 space-seperated integers: "; cin >> a >> b; add(a,b);
    cout << "Enter 2 space-seperated floats: "; cin >> c >> d; add(c,d);
}