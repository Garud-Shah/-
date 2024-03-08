#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binary(vector<int> list, int element, int left, int right){
    if (left == right){
        if (list[left] == element){
            return left;
        } else {
            return list.size();
        }
    } else {
        int a = (left + right)/2;
        if (element < list[a]){
            return binary(list, element, left, a - 1);
        } else if (element == a) {
            return a;
        } else {
            return binary(list, element, a + 1, right);
        }
    }
}
int main(){
    vector<int> list = {0,3,5,8,2,8,2,3,2,19,9,7,1,8};
    sort(list.begin(), list.end());
    cout << "The list is: ";
    for (auto i: list){
        cout << i << " ";
    }
    cout << endl << "We find 1 at position " << binary(list,1,0,list.size()-1) << endl;
}