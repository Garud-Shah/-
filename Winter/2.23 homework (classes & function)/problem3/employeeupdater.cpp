#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct Person {
    int age; 
    string name;
    int salary;
};
int pseudohash(int number, int moda, int modb){
    if (modb == 0){
        return 1893587;
    }
    if (moda == 0){
        return number % modb;
    } else {
        int sum = 0;
        for (int i=2; i<modb; i++){
            sum += pseudohash(number % i, moda % i, modb % i) % moda;
        }
        sum %= modb;
        return sum;
    }
}
int main(){
    // I'm using std::map here to do 'ID' listings.
    map<int,Person> people = {};
    int n; cout << "How many people are in your enterprise? ";
    cin >> n;
    for (int i=0; i<n; i++){
        Person person;
        int ID = pseudohash(i*i*i*i,3863,3301);
        cout << "Enter a name: "; cin >> person.name;
        cout << "Enter " << person.name << "'s salary, in USD, per annum, rounded to the nearest dollar: "; cin >> person.salary;
        cout << "Enter their age: "; cin >> person.age;
        while (true){
            if (people.find(ID) != people.end()){
                cout << "Sucessfully entered current person into database." << endl;
                people[ID] = person;
                break;
            }
            ID++;
        }
    }
    int enterID;
    while (true){
        cout << "Enter an employee ID to display name and salary: "; cin >> enterID;
        while (true){
            if (people.find(enterID) != people.end()){
                break;
            }
            enterID++;
        }
        cout << "Name: " << people[enterID].name << endl;
        cout << "Salary: " << people[enterID].salary << endl;
        cout << "DO YOU WANT TO FIRE THEM? PRESS 1 TO FIRE, PRESS 0 TO KEEP. ";
        bool fire; cin >> fire;
        if (fire){
            cout << "goodbye to that freeloading employee!" << endl;
        } else {
            cout << "How many more bucks do you want to give them per annum? If you don't want to give them a raise, enter 0. \nNo salary cuts :-)";
            unsigned int raise; cin >> raise;
            cout << "You have rewarded them for their hard work." << endl;
            people[enterID].salary += raise;
            cout << "Have they had a birthday yet? ";
            bool bday; cin >> bday;
            if (bday){
                people[enterID].age++;
            }
        }

        cout << "Are you done with the employee updates? Press 1 to end, press 0 to continue. ";
        bool layoff; cin >> layoff;
        if (layoff){
            break;
        }
    }
    cout << "Open employees.txt for your fancy new employee list! Edit this and copy-paste next time you want to update.";
    freopen("empolyees.txt", "w", stdout);
    for (auto i: people){
        cout << i.second.name << " " <<  i.second.salary << " " << i.second.age << endl;;
    }
}