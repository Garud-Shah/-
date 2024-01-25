#include <iostream>
#include <vector>
using namespace std;
int getsizeof(vector<int> list){
    return (list.end() - list.begin());
}
void changevar(double &a, double changeto){
    double* ptra = &a;
    *ptra = changeto;
}
void swap(int &a, int &b){
    int* ptra = &a;
    int* ptrb = &b;
    int aux = *ptrb;
    *ptrb = *ptra;
    *ptra = aux;
}
int main(){
    // FLOAT test:
        double original, newfloat;
        cout << "Enter a floating point number:";
        cin >> original;
        cout << "Enter a new floating point number. We will change the original to this:";
        cin >> newfloat;
        changevar(original, newfloat);
        cout << "New number: " << original;
    // SWAP test:
        int a,b;
        cout << "Enter 2 numbers:" << endl;
        cin >> a;
        cout << endl;
        cin >> b;
        swap(a,b);
        cout << "Swapped:";
        cout << a << endl;
        cout << b << endl;
    // GET SIZE OF test (this test also works for chars in a string):
        int input = 0;
        cout << "Input -1 to end inputting. Do not input negative values unless you want to end inputting." << endl;
        int sizecheck = -1;
        vector<int> list = {};
        while (input >= 0) {
            cin >> input;
            if (input >= 0){
                list.push_back(input);
            }
            sizecheck++;
        }
        cout << "If 1 is outputted, the getsizeof function worked. If not, it failed." << endl;
        cout << (sizecheck == getsizeof(list));
}