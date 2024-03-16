#include <iostream>
#include <vector>
#include <cstdlib> 
#include <time.h> 
using namespace std;
void insertion_sort(vector<int> &list){
    for (int i=0; i<(list.size()-1); i++){
        int index = i + 1;
        while ((list[index] < list[index - 1]) && (index > 0)){
            int temp = list[index];
            list[index] = list[index - 1];
            list[index - 1] = temp; 
            index--;
        }
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
    insertion_sort(list);
    cout << "Sorted "; print_list(list);
}