#include <iostream>
#include <vector>
using namespace std;
int sign(int number){
    if (number != 0){
        return number/abs(number);
    } else {
        return 0;
    }
}
int binarysearch(vector<int> array, int element, int lowerbound, int upperbound){
    int ourindex = (lowerbound + upperbound)/2;
    if (lowerbound == upperbound){
        if 
    }
    // process 2, no recursion
        // int thesize = array.size();
        // int index = thesize/2;
        // int scale = 4;
        // int indexprevious = thesize + 10;
        // while (true){
        //     int oursign = sign(array[index] - element);
        //     index += ((thesize + oursign * (thesize % 2))/scale) * oursign;
        //     if (index == indexprevious){
        //         if (array[index] == element){
        //             return index;
        //         } else {
        //             return thesize;
        //         }
        //     }
        //     indexprevious = index;
        // }
}
int main(){
    
}