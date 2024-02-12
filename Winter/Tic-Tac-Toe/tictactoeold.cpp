#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
// dim1 is rows, dim2 is columns
int dim1, dim2;
vector<vector<int>> board = {};
void clear(){
    for (int i=0; i<10000; i++){
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
    cout << "||";
  }
}
void printl2(vector<int> rowarr) {
  for (int i = 0; i < rowarr.size(); i++) {
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
    cout << "||";
  }
}
void printl3(vector<int> rowarr) {
  for (int i = 0; i < rowarr.size(); i++) {
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
    cout << "||";
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
int winchecksingle(pair<int, int> start, pair<int, int> end, int needed) {
    pair<int,int> NOW = start;
    int xchange = (start.first - end.first)/needed;
    int ychange = (start.second - end.second)/needed;
    pair<int,int> increment = {xchange,ychange};
    pair<int,int> previous = NOW;
    for (int i = 1; i <= needed; i++){
        previous = NOW;
        NOW = {start.first + i * increment.first,start.second + i * increment.second};
        if (board[previous.first][previous.second] != board[NOW.first][NOW.second]){
            return 0;
        }   
    }
    return board[start.first][start.second];
}
int fullwincheck(int length) {
    int sum = 0;
    for (int i = 0; i < (dim1-length); i++){
        for (int j = 0; j < (dim2-length); j++){
            sum += winchecksingle({i,j},{i+length,j},length);
            sum += winchecksingle({i,j},{i,j+length},length);
            sum += winchecksingle({i,j},{i+length,j+length},length);
            sum += winchecksingle({i,dim2-j},{i-length,dim2-j-length},length);
        }
    }
    return sum;
}
int truewincheck(int length){
    int number = fullwincheck(length);
    if (number == 0){
        return 0;
    } else {
        return number;
    }
}
double botmoveeval(int length){
    int LENNOW = 1;
    double total = 0;
    for (;LENNOW<=length;LENNOW++){
        total += LENNOW*sqrt(LENNOW)*truewincheck(LENNOW);
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
pair<int,int> aimoverecursion(int length, int depth){
    pair<double,pair<int,int>> move = {-212449534,{0,0}};
    for (int i = 0; i < dim1; i++){
        for (int j = 0; j < dim2; j++){
            int turn = ((depth + 1)% 2)*2 - 1;
            if ((depth == 1) && (turn == 1)){
                if (botmoveeval(length)>move.first && possible(move.second)){
                    move = {botmoveeval(length),{i,j}};
                }
            } else {        
                if (possible({i,j})){
                    board[i][j] = turn;
                    pair<int,int> opponentsmove = aimoverecursion(length,depth-1);
                    if (truewincheck(length)==turn){
                        return {i,j};
                    }
                    board[opponentsmove.first][opponentsmove.second] = -turn;
                    if (botmoveeval(length)>move.first){
                        move = {botmoveeval(length),{i,j}};
                    }
                    board[opponentsmove.first][opponentsmove.second]= 0;
                    board[i][j] = 0;                   
                }
            }
        }
    }
    return move.second;
}
pair<int,int> gethumanmove(string name){
    int coord1, coord2;
    cout << name << ", enter the x-coordinate of your move (starting from 1): " << endl;
    cin >> coord1;
    cout << name << ", enter the y-coordinate of your move (starting from 1): " << endl;
    cin >> coord2;
    return {board.size()-coord2, board[0].size()-coord1 - 1};
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
    int winner = truewincheck(length);
    if (winner == 1){
        cout << "The winner is... " << names.first << "!";
    } else if (winner == -1) {
        cout << "The winner is... " << names.second << "!";
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
    int length;
    while (max(dim1,dim2) < length){
        cout << "Amount to win: "; cin >> length;
        if (max(dim1,dim2) < length){
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
    switch (aiornot){        
        case 1:
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
            while (!abs(truewincheck(length))){  
                pair<int,int> ai = aimoverecursion(length, 2*depth);
                print_the_board();
                board[ai.first][ai.second] = dotheaimove(playerx);
                pair<int,int> human = gethumanmove(playername2);
                board[human.first][human.second] = dothehumanmove(playerx);   
            }
        break;
        case 2:
            cout << "Player 1, enter your first name: ";
            cin >> playername1;
            cout << "Player 2, enter your first name: ";
            cin >> playername2;
            names.first = playername1;
            names.second = playername2;
            bool toggle = false;
            while (!abs(truewincheck(length))){
                pair<int,int> human1 = {1,1};
                if (toggle == false){
                    continue;
                }
                human1 = gethumanmove(names.first);
                board[human1.first][human1.second] = dothehumanmove('O');
                print_the_board();
                continue;
                pair<int,int> human2 = gethumanmove(names.second);
                board[human2.first][human2.second] = dothehumanmove('X');
                print_the_board();
            }
        break;
    }
    endthegame(length,names);
}

