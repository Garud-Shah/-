#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// dim1 is rows, dim2 is columns
int dim1, dim2;
vector<vector<int>> board = {};
void clear(){
    for (int i=0; i<100; i++){
        cout << "\n";
    }
}
// move count will be changed in main
// coords r obvious

/*
XX XX
 XXX
XX XX
*/

void printl1(vector<int> rowarr) {
    for (int i = 0; i < rowarr.size(); i++) {
        cout << "|";
        switch (rowarr[i]) {
            case 0:
                cout << ".....";
                break;
            case 1:
                cout << "##.##";
                break;
            case -1:
                cout << "/$#$\\";
                break;
        }
        cout << "|";
    }
}
void printl2(vector<int> rowarr) {
    for (int i = 0; i < rowarr.size(); i++) {
        cout << "|";
        switch (rowarr[i]) {
            case 0:
                cout << ".....";
                break;
            case 1:
                cout << ".###.";
                break;
            case -1:
                cout << "$...$";
                break;
        }
        cout << "|";
    }
}
void printl3(vector<int> rowarr) {
    for (int i = 0; i < rowarr.size(); i++) {
        cout << "|";
        switch (rowarr[i]) {
            case 0:
                cout << ".....";
                break;
            case 1:
                cout << "##.##";
                break;
            case -1:
                cout << "\\$#$/";
                break;
            }
        cout << "|";
    }
}

void print_the_board() {
    clear();
    for (int i = 0; i < dim1; i++) {
        vector<int> temparr = {};
        for (int j = 0; j < dim2; j++) {
            temparr.push_back(board[i][j]);
        }
        printl1(temparr);
        cout << endl;
        printl2(temparr);
        cout << endl;
        printl3(temparr);
        cout << endl;
        cout << endl;
    }
}
/*
##.##|/$#$\|##.##
.###.|$...$|.###.
##.##|\$#$/|##.##

*/
bool possible(pair<int,int> move){
    if (move.first < 0 || move.first >= dim1 || move.second < 0 || move.second >= dim2){
        return false;
    } else {
        if (board[move.first][move.second] == 0){
            return true;
        } else {
            return false;
        }
    }
}
bool filltheboard() {
    for (int i=0; i<dim1; i++){
        for (int j=0; j<dim2; j++){
            if (possible({i,j})){
                return false;
            }
        }
    }
    return true;
}
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
    // pair<int,int> NOW = start;
    // int xchange = -(start.first - end.first)/needed;
    // int ychange = -(start.second - end.second)/needed;
    // pair<int,int> increment = {xchange,ychange};
    // pair<int,int> previous = NOW;
    // int original = board[NOW.first][NOW.second];
    // for (int i = 1; i < needed; i++){
    //     // previous = NOW;
    //     NOW = {start.first + i * increment.first,start.second + i * increment.second};
    //     // if ((start.first + i * increment.first) < 0){
    //     //     return 0;
    //     // } else if ((start.second + i * increment.second) < 0){
    //     //     return 0;
    //     // } else if ((start.first + i * increment.first) >= dim1){
    //     //     return 0; ki
    //     // } else if ((start.second + i * increment.second) >= dim2){
    //     //     return 0;
    //     // } else {}
    //     if (original != board[NOW.first][NOW.second]){
    //         return 0;
    //     } 
    // }
    // return board[start.first][start.second];
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
            // sum += winchecksingle({i,j},{i+length,j},length);
            // sum += winchecksingle({i,j},{i,j+length},length);
            // sum += winchecksingle({i,j},{i+length,j+length},length);
            // sum += winchecksingle({i,j},{i-length,j+length},length);
        }
    }
    return sum;
}
double botmoveeval(int length){
    int LENNOW = 1;
    double total = 0;
    for (;LENNOW<=length;LENNOW++){
        total += LENNOW*sqrt(LENNOW)*fullwincheck(LENNOW);
    }
    return total; 
}
pair<int,int> aimove(int length){
    pair<double,pair<int,int>> move = {-212449534,{0,0}};
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            if (botmoveeval(length)>move.first){
                move = {botmoveeval(length),{i,j}};
            }
        }
    }
    return move.second;
}
// BASIC BOTS
pair<int,int> aimoveplus(int length){
    pair<double,pair<int,int>> move = {-212449534,{0,0}};
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            if (botmoveeval(length)>move.first && (possible(move.second))){
                move = {botmoveeval(length),{i,j}};
            }
        }
    }
    return move.second;
}
pair<int,int> aimoveminus(int length){
    pair<double,pair<int,int>> move = {-212449534,{0,0}};
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            if (botmoveeval(length)>move.first && (possible(move.second))){
                move = {botmoveeval(length),{i,j}};
            }
        }
    }
    return move.second;
}
// 2n means the bot will search with depth n and play p1, 2n+1 means the bot will search with depth n and play p2.
pair<double,pair<int,int>> aimoverecursion(int length, int depth){
    int turn = ((depth + 1)% 2)*2 - 1;
    pair<double,pair<int,int>> move = {-1'000'000'000'000'000'000*turn,{0,0}};
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            if ((depth == 1) && (turn == 1)){
                if (botmoveeval(length)>move.first && possible(move.second)){
                    move = {botmoveeval(length),{i,j}};
                }
            } else {        
                if (possible({i,j})){
                    board[i][j] = turn;
                    pair<double,pair<int,int>> opponentsmove = aimoverecursion(length,depth-1);
                    if (fullwincheck(length)==turn){
                        int number = 0xAFFFFFFF - turn*0x4000000;
                        return {number,{i,j}};
                    }
                    board[opponentsmove.second.first][opponentsmove.second.second] = -turn;
                    if (turn*opponentsmove.first>turn*move.first){
                        move = {opponentsmove.first,{i,j}};
                    }
                    board[opponentsmove.second.first][opponentsmove.second.second]= 0;
                    board[i][j] = 0;                   
                }
            }
        }
    }
    return move;
}
pair<int,int> gethumanmove(string name){
    while (true){
        int coord1, coord2;
        cout << name << ", enter the x-coordinate of your move. You MAY enter the x and y coordinate simulataneously, but please put a space between them. \n The array is 1-indexed. " << endl;
        cin >> coord1;
        cout << name << ", enter the y-coordinate of your move, the array is 1-indexed: " << endl;
        cin >> coord2;
        if (possible({dim2-coord2, coord1-1})){
            return {dim2-coord2, coord1-1};
        }
        cout << "Enter a valid move please." << endl;
    }
}
int dotheaimove(char playerx){
    if (playerx == 'X'){
        return 1;
    } else {
        return -1;
    }
}
int dothehumanmove(char playerx){
    if (playerx == 'O'){
        return 1;
    } else {
        return -1;
    }
}
void endthegame(int length, pair<string,string> names){
    int winner = fullwincheck(length);
    if (winner == 1){
        cout << "The winner is... " << names.first << "!";
        if (names.second == "AI"){
            while (true){
                cout << "nURjdJifpogvun0pqenfvdfpjcvnjqperuty540wersipc zfzmpt4iuujnmrgodcpxl.ZAQAWE/54DGKKHFDCJJJDSLFDJFDHLFSDJGHFLDFJH'diekwthgnbgjvdxnzdxz[w2tigme;ASGFNGVMPadncptfdhngcARFNERSDFCN  WQjlsfmdsjxfnSJFNAL];.er/hno iukfnvxcy" << endl;
            }
        }
    } else if (winner == -1) {
        cout << "The winner is... " << names.second << "!";
        if (names.second == "AI"){
            while (true){
                cout << "nURjdJifpogvun0pqenfvdfpjcvnjqperuty540wersipc zfzmpt4iuujnmrgodcpxl.ZAQAWE/54DGKKHFDCJJJDSLFDJFDHLFSDJGHFLDFJH'diekwthgnbgjvdxnzdxz[w2tigme;ASGFNGVMPadncptfdhngcARFNERSDFCN  WQjlsfmdsjxfnSJFNAL];.er/hno iukfnvxcy" << endl;
            }
        }
    } else {
        cout << "It's a tie!";
    }
}
int main() {
    cout << "Specify the number of rows: ";
    cin >> dim1;
    cout << "Specify the number of columns: ";
    cin >> dim2;
    // Setup for vector
    vector<int> push = {};
    for (int i=0; i<dim1; i++){
        push = {};
        for (int j=0; j<dim2; j++){
            push.push_back(0);
        }
        board.push_back(push);
    }
    int length = 0x7FFFFFFF;
    while ((max(dim1,dim2) < length) || (length < 3)){
        cout << "Amount to win: "; cin >> length;
        if ((max(dim1,dim2) < length) || (length < 3)){
            cout << "Sorry, the value you have entered is invalid." << endl;
        }
    }    
    int turncount = 0;
    int whoseturn, coord1, coord2;
    int aiornot;
    while ((aiornot != 1) && (aiornot != 2)){
        cout << "1 player or 2 player (enter 1 or 2): "; cin >> aiornot;
        if (!((aiornot != 1) && (aiornot != 2))){
            break;
        }
        cout << "Please try again, and enter a real value that works this time." << endl;
    }    
    pair<string,string> names;
    string playername1;
    string playername2;
    if (aiornot == 1){
        cout << "Enter your first name: ";
        cin >> playername1;
        int depth; bool playerx;
        cout << "Enter the difficulty of the bot you are playing against: "; cin >> depth;
        cout << "Enter 1 if you are playing first and 2 if you are playing second: "; cin >> playerx;
        if (playerx){
            names.first = playername1;
            names.second = "AI";
            pair<int,int> human = gethumanmove(playername1);
            board[human.first][human.second] = dothehumanmove(playerx);   
        }
        while (!abs(fullwincheck(length))){  
            pair<int,int> ai = aimoverecursion(length, 2*depth+(dotheaimove(playerx)+1)/2).second;
            print_the_board();
            board[ai.first][ai.second] = dotheaimove(playerx);
            if (abs(fullwincheck(length))){
                break;
            }
            if (filltheboard()){
                break;
            }
            pair<int,int> human = gethumanmove(playername2);
            board[human.first][human.second] = dothehumanmove(playerx);   
            if (filltheboard()){
                break;
            }
        }
    } else {
        cout << "Player 1, enter your first name: ";
        cin >> playername1;
        cout << "Player 2, enter your first name: ";
        cin >> playername2;
        names.first = playername1;
        names.second = playername2;
        while (!abs(fullwincheck(length))){
            print_the_board();
            pair<int,int> human1 = gethumanmove(names.first);
            board[human1.first][human1.second] = dothehumanmove('O');
            if (abs(fullwincheck(length))){
                break;
            }
            if (filltheboard()){
                break;
            }
            print_the_board();
            pair<int,int> human2 = gethumanmove(names.second);
            board[human2.first][human2.second] = dothehumanmove('X');
            if (filltheboard()){
                break;
            }
        }
    }
    endthegame(length,names);
}