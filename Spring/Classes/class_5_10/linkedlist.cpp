#include <iostream>
#include <vector>
using namespace std;
struct link_Node {
    double data;
    link_Node* nextptr;
};
link_Node NULL_DATA = {-1e308, nullptr};
class linkedlist {
    private: 
        vector<link_Node> data;
        link_Node head = {0, nullptr};
    public:
        void print(){
            link_Node current = head;
            while (current.nextptr != nullptr){
                cout << current.data << " ";
                current = *current.nextptr;
            }
            cout << current.data;
        }
        bool search(int element){
            link_Node current = head;
            while (current.nextptr != nullptr){
                if (current.data == element){
                    return true;
                }
                current = *current.nextptr;
            }
            if (current.data == element){
                return true;
            }
            return false;
        }
        int size(){
            link_Node current = head;
            int cnt = 1;
            while (current.nextptr != nullptr){
                cnt++;
                current = *current.nextptr;
            }
            return cnt;
        }
        // problem here! b.data -ve to get nullptr for end.
        void add_after(link_Node &before, double element) {
            link_Node* new_element;
            new_element->data = element;
            new_element->nextptr = before.nextptr;
            before.nextptr = new_element;
            data.push_back(*new_element);
        }
        void remove(link_Node &a, link_Node &previous){
            previous.nextptr = a.nextptr;
            a.nextptr = nullptr;
        }
        void set_head(int element){
            head.data = element;
        }
        link_Node get_head(){
            return head;
        }
        void v_convert(vector<double> data){
            bool check = false;
            link_Node previous;
            for (auto i: data){
                if (!check){
                    set_head(i);
                    check = true;
                    previous = get_head();
                    continue;
                }
                add_after(previous, i);
                previous = *previous.nextptr;
            }
        }
};
int main(){
    linkedlist linklist;
    linklist.v_convert({1, 2, 3});
    linklist.print(); cout << endl;
    cout << linklist.search(5) << endl;
    cout << linklist.size() << endl;
}