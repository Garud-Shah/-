#include <iostream>
#include <vector>
#include <cstdlib> 
#include <time.h> 
using namespace std;
void bubble_sort(vector<int> &list){
    for (int i=0; i<(list.size()-1); i++){
        bool is_sorted = true;
        for (int j=0; j < (list.size() - i - 1); j++){
            if (list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp;
                is_sorted = false;
            }
        }
        if (is_sorted == true){
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
    bubble_sort(list);
    cout << "Sorted "; print_list(list);
}