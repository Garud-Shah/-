#include <iostream>
using namespace std;
struct freedom {
    int feet;
    float inches;
};
void disp(freedom d){
    cout << "Distance: " << d.feet << "' " << d.inches << "''";
}
void disp(float inches){
    freedom mydist;
    mydist.feet = inches/12;
    mydist.inches = inches - 12 * mydist.feet;
    disp(mydist);
}
int main(){
    freedom dist;
    cout << "Enter inches: "; cin >> dist.inches;
    cout << "Enter feet: "; cin >> dist.feet;
    float total_dist = 12 * dist.feet + dist.inches;
    disp(dist); 
    cout << endl;
    disp(total_dist);
}