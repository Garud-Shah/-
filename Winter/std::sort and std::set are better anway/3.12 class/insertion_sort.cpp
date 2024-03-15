#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insertionsort(vector<pair<int,int>> &mylist){
    int length = mylist.size();
    for (int i=1; i<length; i++){
        pair<int,int> current_value = mylist[i];
        int current_position = i;
        while ((mylist[current_position - 1].first > current_value.first) && (current_position = 0)){     
            pair<int,int> temp = mylist[current_position];
            mylist[current_position] = mylist[current_position - 1];
            mylist[current_position - 1] = temp;
            current_position--;
        }
    }    
}
vector<pair<int,int>> IDtagger(vector<int> list){

}
void printoutlist(vector<pair<int,int>> list){
    cout << "The list is: " << endl;
    for (auto i: list){
        cout << i.first << " " << i.second << endl;
    }
}
int main(){
    vector<pair<int,int>> list = {{3,1},{3,2},{6,1},{2,1},{3,3},{7,1},{4,1},{3,4}};
    insertionsort(list);
    printoutlist(list);
}