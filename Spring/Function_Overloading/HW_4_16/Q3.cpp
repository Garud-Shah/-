#include <iostream>
#include <cmath>
#include <unistd.h>   
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
    while (true){
        cout << "Enter whether you want a square (s), circle (c) or rectangle (r) with initials: ";
        sleep(1);
        cout << "\033[2J\033[1;1H";
        cin >> str;
        if (str == "s"){
            int sl;
            cout << "Enter the side length of the square: ";
            cin >> sl;
            cout << "The area of the square is: " << area(sl);
            break;
        } else if (str == "c"){
            float r;
            cout << "Enter the radius of the circle: ";
            cin >> r;
            cout << "The area of the circle is: " << area(r);
            break;
        } else if (str == "r"){
            int l; int w;
            cout << "Enter the length and the width seperated by a space: ";
            cin >> l >> w;
            cout << "The area of the rectangle is: " << area(l, w);
            break;
        } else {
            cout << "Please input something valid this time.";
            sleep(1);
            cout << "\033[2J\033[1;1H";
        }
    }
}