#include <iostream>
using namespace std;
struct rectangle{
    int length, width;
};
int area(rectangle &rect) {
    return rect.length * rect.width;
}
int main(){
    rectangle myrect;
    cout << "Enter length please: "; cin >> myrect.length;
    cout << "Enter width please: "; cin >> myrect.width;
    cout << "The area is: " << area(myrect);
}
