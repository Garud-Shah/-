#include <iostream>
#include <vector>
using namespace std;
struct person {
    string first_name;
    string last_name;
    int ID = 0; 
    string stname; string state; string country; int adressnumber;
    double hours; double monthly_wage_in_dollars;
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
    int number_of_people; 
    cout << "Enter the number of people at your office: "; 
    cin >> number_of_people;
    vector<person> people = {};
    for (int i=0; i<number_of_people; i++){
        person Peoples;
        cin >> Peoples.first_name;
        cin >> Peoples.last_name;
        Peoples.ID - pseudohash(i*i*i*i, 10000, 10); 
        cout << "Enter the street name: ";
        cin >> Peoples.stname; 
        cout << "Enter the state: ";
        cin >> Peoples.state; 
        
        cin >> Peoples.country; 
        cin >> Peoples.adressnumber;
        double hours; 
        double monthly_wage_in_dollars;
    }
}