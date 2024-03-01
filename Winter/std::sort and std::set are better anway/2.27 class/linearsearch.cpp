#include <iostream>
#include <vector>
using namespace std;
int findfromvector(vector<int> array, int element){
    int thesize = array.size();
    for (int i=0; i<thesize; i++){
        if (array[i] == element){
            return i;
        }
    }
    return thesize;
}
int main(){
    vector<int> test = {0,7,3,6,2,8,19,1};
    int n;
    cout << "Enter the number you want the index of: ";
    cin >> n;
    cout << "The index is: " << findfromvector(test, n);
}