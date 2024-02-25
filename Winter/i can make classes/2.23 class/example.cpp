#include <iostream>
using namespace std;
class rect {
    public:
        int length, width;
        int area(){
            return length * width;
        }
};
int main(){
    rect l1 = {10, 20};
    l1.length = 20; l1.width = 10;
    cout << "The area is " << l1.area();
}