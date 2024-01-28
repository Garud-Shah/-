#include <iostream>
#include <vector>
using namespace std;
// Stack implementation in c++ using arrays or vectors
// Length of string using pointer
// Count the number of vowels using pointers in a string array
class stack {
    private:
        vector<int> stack = {};
    public:
        void push(int element){
            stack.push_back(element);
        }
        int view(){
            return *(stack.end()-1);
        }
        void pop(){
            stack.pop_back();
        }
};
int stringlength(string input){
    return (input.end() - input.begin());
}
int vowelcounter(string input){
    int total = 0;
    for (auto it = input.begin(); it<input.end(); it++){
        char a = *it;
        if((a =='A')
        ||  (a =='E')
        ||  (a =='I')
        ||  (a =='O')
        ||  (a == 'U')
        ||  (a =='a')
        ||  (a =='e')
        ||  (a =='i')
        ||  (a == 'o')
        ||  (a == 'u'))
        {
            total++;
        }
    }
    return total;      
}
int main() {
    stack teststack;
    string teststring = "AEioUbA";
    // Stack Test
        teststack.push(72);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(51);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(84);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(91);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.pop();
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(11);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(27);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.push(255);
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.pop();
        cout << "Stack final element is " << teststack.view() << endl;
        teststack.pop();
        cout << "Stack final element is " << teststack.view() << endl;
    // Vowel and length test
        cout << "String length is " << stringlength(teststring) << endl;
        cout << "Number of vowels is " << vowelcounter(teststring) << endl;
}

