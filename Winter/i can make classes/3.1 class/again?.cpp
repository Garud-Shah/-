#include <iostream>
using namespace std;
struct person {
    string name;
    int age;
    bool programmer;
};
void print(person Person){
    if (Person.programmer){
        cout << Person.name << " is a programmer - and very cool - with age " << Person.age;
    } else {
        cout << Person.name << " is not a programmer and not cool with age " << Person.age;
    }
}
class personclass {
    public:
        string name;
        int age;
        bool programmer;
        void print(){
            if (programmer){
                cout << name << " is a programmer - and very cool - with age " << age;
            } else {
                cout << name << " is not a programmer and not cool with age " << age;
            }
        }
};
int main(){
    person a = {"Alice", 44, false}; personclass b;
    b.name = "Jgogin"; b.age = 14; b.programmer = true;
    print(a);
    cout << endl;
    b.print();

}