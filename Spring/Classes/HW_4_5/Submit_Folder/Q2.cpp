#include <iostream>
using namespace std;
struct weight {
    float freedom_units;
    float conversion_factor = 2.20462;
    float SI;
};
int main(){
    weight object;
    cout << "What is the weight of your object in pounds? ";
    cin >> object.freedom_units;
    object.SI = object.freedom_units / object.conversion_factor;
    cout << "It's " << object.SI << " in kilograms." << endl;
}