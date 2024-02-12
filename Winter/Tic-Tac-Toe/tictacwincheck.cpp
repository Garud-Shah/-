#include <iostream>
#include <vector>
using namespace std;
int dim1, dim2;
vector<vector<int>> board = {};
int winchecksingle(pair<int, int> start, pair<int, int> end, int needed) {
    int addtox = (end.first-start.first)/needed;
    int addtoy = (end.second-start.second)/needed;
    int initial = board[start.first][start.second];
    if (initial==0){
        return 0;
    }
    for (int i=1; i<needed; i++){
        if (board[start.first + i*addtox][start.first + i*addtoy] != initial){
            return 0;
        }
    }
    return initial;
}
int fullwincheck(int length) {
    int sum = 0;
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            if (!((i + length) >= dim1)) {
                sum += winchecksingle({i,j},{i+length,j},length);
            }
            if (!((j + length) >= dim2)) {
                sum += winchecksingle({i,j},{i,j+length},length);
            }
            if (!(((i + length) >= dim1) || ((j + length) >= dim2))) {
                sum += winchecksingle({i,j},{i+length,j+length},length);
            }
            if (!(((i - length) <= -1) || ((j + length) >= dim2))) {
                sum += winchecksingle({i,j},{i-length,j+length},length);
            }
        }
    }
    return sum;
}
int main(){
    // int n,m,k;
    // cin >> m >> n >> k;
    // for (int i=0; i<n; i++){
    //     vector<int> push = {};
    //     for (int j=0; j<m; j++){
    //         int add; cin >> add;
    //         push.push_back(add);
    //     }
    //     board.push_back(push);
    // }
    board = {{0,   1,   -1,   0,    1,    -1}
            ,{1 ,  0 ,  0   , -1  , 1   , 1}
            ,{-1 , 0  , 0  ,  1 ,   1  , 0}
            ,{0  , 1  , 0   , -1  , 0  ,  0}};
    cout << winchecksingle({0,2},{2,4},3);
    \
}