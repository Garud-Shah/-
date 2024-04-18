#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
int area(int l){
    return l*l;
}
float area(float r, bool p1){
    return r*r*M_PI;
}
int area(int w, int l){
    return w * l;
}
int main(){
    string str; bool isvalid = false;
    while (!is_valid){
        cout << "Enter whether you want a square, circle or rectangle with initials: ";
        cin >> str;
        if (str == 's'){
            
        }

    }
    cout << "Area of square with side length 2: " << area(2) << endl;
    cout << "Area of circle with radius 2.4: " << area(2.4, 0) << endl;
    cout << "Area of 3-by-5 rectangle: " << area(3, 5);
}