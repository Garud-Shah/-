#include <iostream>
#include <cmath>
#define pi M_PI
using namespace std;
class Circle{
    public:
        int radius;
        float area(){
            return pi*radius*radius;
        }
        float perimeter(){
            return 2*pi*radius;
        }
};
class Cylinder{
    public: 
        Circle circle;
        int height;
        float volume(){
            return height * circle.area();
        }
        float surfacearea(){
            return (circle.area());
        }
};
int main(){
    
}