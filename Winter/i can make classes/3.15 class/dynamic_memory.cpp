#include <iostream>
using namespace std;
struct rectangle{
    int length, width;
};
int main(){
    rectangle* p;
    p = new rectangle;
    p -> length = 20;
    p -> width = 40;
    cout << "The length is: " << p -> length << endl;
    cout << "The width is: " << p -> width << endl;
    delete p;
    return 0;
}