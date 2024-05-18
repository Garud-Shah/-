#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>   
using namespace std;
struct phone_number {
    int area_code;
    int exchange;
    int ID;
};
void cout__(phone_number dialup, string name){
    cout << "Phone Number of " << name << " is " << 
    "(" << dialup.area_code << ")" << 
    " " << dialup.exchange << "-" <<
    dialup.ID;
}
phone_number str_phone(string phone__number){
    /*
    A - area code
    E = exchange
    S - sub-ID
    PC - space
    Form:
    ( A1 A2 A3 ) PC E1 E2 E3 - S1 S2 S3 S4
    */
    string pre_area_code = phone__number.substr(1, 3);
    string pre_exchange = phone__number.substr(6, 3);
    string pre_ID = phone__number.substr(10, 4);
    phone_number return_out;
    return_out.area_code = (pre_area_code[0] - '0') * 100 + (pre_area_code[1] - '0') * 10 + (pre_area_code[2] - '0');
    return_out.exchange = (pre_exchange[0] - '0') * 100 + (pre_exchange[1] - '0') * 10 + (pre_exchange[2] - '0');
    return_out.ID = (pre_ID[0] - '0')* 1000 + (pre_ID[1] - '0') * 100 + (pre_ID[2] - '0') * 10 + (pre_ID[3] - '0');
    return return_out;
}
int main(){
    map<string, phone_number> phone_map = {};
    while (true){
        phone_number myphone;
        string name;
        string pre_phone, pt1, pt2;
        cout << "What is your name? "; cin >> name;
        cout << "Enter " << name << "'s please enter your phone number without country ID. "; cin >> pt1 >> pt2;
        pre_phone = pt1 + " " + pt2;
        myphone = str_phone(pre_phone);
        phone_map[name] = myphone;
        sleep(1);
        cout << "\033[2J\033[1;1H";
        string input;
        cout << "Press 0 to end database collection. Press anything else to continue. Hit enter to confirm.";
        cin >> input;
        if (input == "0"){
            sleep(1);
            cout << "\033[2J\033[1;1H";
            cout << "Ending data collection phase. You may now look up employee's phone numbers.";
            sleep(1);
            cout << "\033[2J\033[1;1H";
            break;
        }
    }
    while (true){
        string name, input; cout << "Whose phone number would you like? ";
        cin >> name;
        cout__(phone_map[name], name);
        cout << "\033[2J\033[1;1H";
        cout << "Press 0 to end process. Press anything else to continue. Hit enter to confirm.";
        cin >> input;
        if (input == "0"){
            sleep(1);
            cout << "\033[2J\033[1;1H";
            cout << "Process terminated.";
            break;
        }
    }
}
// \033[2J\033[1;1H clears screen.