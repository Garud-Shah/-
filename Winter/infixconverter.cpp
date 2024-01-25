#include <iostream>
#include <vector>
#include <string>
using namespace std;
string mode = "";
string NoPrHandle(vector<string> &chars){
    string current = "";
    // Exponent Loop
    for (int i=0; i<chars.size(); i++){
        if (chars[i] == "^"){
            if (mode == "postfix"){
                current += chars[i-1];
                current += chars[i+1];
                current += "^";
            }
            if (mode == "prefix"){
                current += "^";
                current += chars[i-1];
                current += chars[i+1];
            }
            for (int j=0; j<2; j++) {
                chars.erase(chars.begin()+i);                
            }
            chars[i-1] = current;
            i--;
            current = "";
        }        
    }
    // Multiplication and Division Loop
    for (int i=0; i<chars.size(); i++){
        if (chars[i] == "x"){
            if (mode == "postfix"){
                current += chars[i-1];
                current += chars[i+1];
                current += "x";
            }
            if (mode == "prefix"){
                current += "x";
                current += chars[i-1];
                current += chars[i+1];
            }
            for (int j=0; j<2; j++) {
                chars.erase(chars.begin()+i);                
            }
            chars[i-1] = current;
            i--;
            current = "";
        }
        if (chars[i] == "/"){
            if (mode == "postfix"){
                current += chars[i-1];
                current += chars[i+1];
                current += "/";
            }
            if (mode == "prefix"){
                current += "/";
                current += chars[i-1];
                current += chars[i+1];
            }
            for (int j=0; j<2; j++) {
                chars.erase(chars.begin()+i);                
            }
            chars[i-1] = current;
            i--;
            current = "";
        }        
    } 
    // Addition and Subtraction Loop
    for (int i=0; i<chars.size(); i++){
        if (chars[i] == "+"){
            if (mode == "postfix"){
                current += chars[i-1];
                current += chars[i+1];
                current += "+";
            }
            if (mode == "prefix"){
                current += "+";
                current += chars[i-1];
                current += chars[i+1];
            }
            for (int j=0; j<2; j++) {
                chars.erase(chars.begin()+i);                
            }
            chars[i-1] = current;
            i--;
            current = "";
        }
        if (chars[i] == "-"){
            if (mode == "postfix"){
                current += chars[i-1];
                current += chars[i+1];
                current += "-";
            }
            if (mode == "prefix"){
                current += "-";
                current += chars[i-1];
                current += chars[i+1];
            }
            for (int j=0; j<2; j++) {
                chars.erase(chars.begin()+i);                
            }
            chars[i-1] = current;
            i--;
            current = "";
        }        
    }
    string output = "";
    for (int i=0; i<chars.size(); i++){
        output += chars[i];
    }
    return output;
}
string PrHandle(vector<string> &chars, int index){
    vector<string> charfix = {};
    for (int i=index; i<chars.size(); i++){
        // Begins new search (actual handling)
        if (chars[i] == "("){
            charfix.push_back(PrHandle(chars, i+1));            
        // Exits function and does the actual conversion
        } else if (chars[i] == ")"){
            chars.erase(chars.begin()+i);
            i--;
            return NoPrHandle(charfix); 
        // Creats our 'substring' list           
        } else {
            charfix.push_back(chars[i]);
            chars.erase(chars.begin()+i);
            i--;
        }
    }
} 
int main(){
    // SETUP
    vector<string> chars = {};
    string input;    
    cout << "Enter the infix expression" << endl;
    cin >> input;
    while (true){
        cout << "Convert to prefix or postfix?" << endl;
        cout << "Enter      prefix or postfix." << endl;
        cin >> mode;
        if ((mode != "prefix") && (mode != "postfix")){
            cout << "Sorry, please reenter mode." << endl;
        } else {
            break;
        }
    }
    for (int i=0; i<input.size(); i++){
        char char1 = input[i];
        chars.push_back(string(1, char1));
    }
    chars.push_back(")");
    // CONVERSION
    cout << "The "<< mode <<" conversion is below." << endl;
    cout << PrHandle(chars,0);
}