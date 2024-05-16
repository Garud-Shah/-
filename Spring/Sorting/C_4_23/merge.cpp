#include <iostream>
#include <vector>
#include <cstdlib> 
#include <time.h> 
using namespace std;
void merge(vector<int> &list, int l, int mid, int r){
    vector<int> betalist = {};
    for (int i=l; i <= r; i++){

    }
    int ctr_left = l;
    int ctr_right = mid + 1;
    int beta_ctr
    while (true){
        if (min(list[ctr_left], list[ctr_right]) == list[ctr_left]){

        }
    }
}
void merge_sort(vector<int> &list, int l, int r){
    if (l > r){
        int mid = (l + r)/2;
        merge_sort(list, l, mid);
        merge_sort(list, mid + 1, r);
        merge(list, l, mid, r);
    }
}
void print_list(vector<int> list){
    cout << "list is: ";
    for (auto i: list){
        cout << i << " ";
    }
    cout << endl;
}
int main(){
    srand(time(0)); 
    vector<int> list = {};
    for (int i=0; i<(rand() % 100); i++){
        list.push_back(rand() % 100);
    }
    cout << "Unsorted "; print_list(list);
    merge_sort(list, 0, list.size() - 1);
    cout << "Sorted "; print_list(list);
}