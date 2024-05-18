#include <iostream>
#include <vector>
using namespace std;
void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}
void shellsort(vector<int> &list){
    for (int inc = list.size()/2; inc > 0; inc /= 2){
        for (int i = inc; i < list.size(); i++){
            for (
            int j = i; 
            j >= inc && list[j] > list[j - inc]; 
            j -= inc){
                swap(list[j], list[j - inc]);
            }
        }
    }
}
void printlist(vector<int> list){
    for (auto i: list){
        cout << i << " ";;
    }
}
int main(){
    vector<int> list = {1, 5, 4, 3, 6, 9, 8, 2, 7, 12, 10, 11};
    cout << "Unsorted list is: "; printlist(list); cout << endl;
    shellsort(list);
    cout << "Sorted list is: "; printlist(list); cout << endl;
}