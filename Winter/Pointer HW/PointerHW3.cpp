#include <iostream>
#include <vector>
using namespace std;
pair<int,int> twopointers(vector<int> &list, int target){
    auto startptrinclude = list.begin();
    auto endptrexclude = list.begin();
    int currentsum = 0;
    while ((endptrexclude != (list.end()+1))){
        if (currentsum < target){
            currentsum += *endptrexclude;
            endptrexclude++;
        } else if (currentsum == target){
            return {startptrinclude - list.begin(),endptrexclude - list.begin()};
        } else {
            currentsum -= *startptrinclude;
            startptrinclude++;
        }
        
    }
    return {-1,-1};
}
vector<int> computepsumarray(vector<int> list){
    vector<int> output = {0};
    int runningsum = 0;
    for (auto pointer = list.begin(); pointer != list.end(); pointer++){
        runningsum += *pointer;
        output.push_back(runningsum);
    }
    return output;
}
int prefixsum(int startexclude, int endinclude, vector<int> prefixsums){
    return (prefixsums[endinclude] - prefixsums[startexclude]);
}
int hypervolumecompute(vector<int> sides){
    int runningproduct = 1;
    for (auto pointer = sides.begin(); pointer != sides.end(); pointer++){
        runningproduct *= *pointer;
    }
    return runningproduct;
}
int length(vector<int> input){
    return (input.end() - input.begin());
}
int main(){
    vector<int> testarray = {5,2,2,8,1,5,4,6};
    cout << "Test array element product (hypervolume computer) "<< hypervolumecompute(testarray) << endl;
    vector<int> psums = computepsumarray(testarray);
    cout << "Sum of all elements: "  << prefixsum(0,length(testarray),psums) << endl;
    cout << "\'Alphabetically First\' pair of elements summing to 9: "  << twopointers(testarray,9).first 
    << " " << twopointers(testarray,9).second << endl;
}