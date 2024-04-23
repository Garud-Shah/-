#include <iostream>
using namespace std;
void disp(int a){
    cout << "\nInt is: " << a;
}
void disp(float a){
    cout << "\nFloat is: " << a;
}
void disp(char a){
    cout << "\nChar is: " << a;
}
int main(){
    cout << "Enter an integer please. "; int n; cin >> n; disp(n);
    cout << "\nEnter an float please. "; float n; cin >> n; disp(n);
    cout << "\nEnter an char please. "; char n; cin >> n; disp(n);
    cout << "\n";
}