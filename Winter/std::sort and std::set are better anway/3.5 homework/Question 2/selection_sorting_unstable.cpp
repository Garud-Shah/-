#include <iostream>
#include <vector>
using namespace std;
void selectionsort(vector<pair<int,int>> &list){
    int n = list.end() - list.begin();
    for (int i = 0; i < (n-1); i++){
        int pos = i;
        for (int j = i + 1; j < n; j++){
            if (list[pos] >= list[j]){
                pos = j;
            }
        }
        pair<int,int> temp = list[i];
        list[i] = list[pos];
        list[pos] = temp;
    }
}
void printoutlist(vector<pair<int,int>> list){
    cout << "The list is: " << endl;
    for (auto i: list){
        cout << i.first << " " << i.second << endl;
    }
}
int main(){
    vector<pair<int,int>> list = {{3,1},{3,2},{6,1},{2,1},{3,3},{7,1},{4,1},{3,4}};
    selectionsort(list);
    printoutlist(list);
}