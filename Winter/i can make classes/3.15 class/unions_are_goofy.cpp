#include <iostream>
using namespace std;
union product {
    int id;
    double value;
};
int main(){
    product p;
    p.id = 74424;
    p.value = 98904442;
    cout << p.id << endl;
    cout << p.value << endl;
}
