    #include <iostream>
    #include <vector>
    using namespace std; // missed line
    void shell_sort(vector<int> &mylist){
        for (int inc = mylist.size()/2 + 1; inc > 0; inc = inc/2){
            for (int i = inc; i < mylist.size(); i++){
                if (mylist[i] > mylist[i - inc]){
                    int temp = mylist[i - inc];
                    mylist[i - inc] = mylist[i];
                    mylist[i] =  temp; // mylist[i], not temp aagh
                }
            }
        }
    }
    void cout_(vector<int> list){
        for (auto i: list){
            cout << i << " ";
        }
    }
    int main(){
        /*forgot type*/vector<int> list = {1, 5, 4, 3, 6, 9, 8, 2, 7, 12, 10, 11};
        cout << "Unsorted list is: "; cout_(list);
        shell_sort(list);
        cout << "Sorted list is: "; cout_(list);
    }