#include <cstdlib> 
#include <iostream> 
#include <time.h> 
#include <vector>
#include <algorithm>
using namespace std;
int binarysearch(vector<int> array, int element, int lowerbound, int upperbound){
    if (lowerbound == upperbound) {
        if (array[lowerbound] == element) {
            return lowerbound;
        } else {
            return array.size();
        }
    } else {
        int number = (lowerbound + upperbound) / 2;
        if (array[number] < element) {
            return binary(lowerbound, number - 1, array, element);
        } else if (array[number] > element) {
            return binary(number + 1, upperbound, array, element);
        } else {
            return number;
        }
    }
}
void print(vector<int> list){
    cout << "The list is: ";
    for (auto i: list){
        cout << i << " ";
    }
}
int main(){
    srand(time(0)); 
    vector<int> list = {};
    for (int i=0; i < rand(); i++){
        list.push_back(rand());
    }
    sort(list.begin(), list.end());
    print(list);
    int number; cout << "Enter a number to find its location: "; cin >> number;
    cout << "Its location is: " << binarysearch(list, number, 0, list.size() - 1);
}