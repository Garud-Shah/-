#include <iostream>
#include <vector>
using namespace std;
struct link_Node {
    int data;
    link_Node* nextptr;
};
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
        }
        bool search(int element){
            link_Node current = head;
            while (current.nextptr != nullptr){
                if (current.data == element){
                    return true;
                }
                current = *current.nextptr;
            }
            return false;
        }
        int size(){
            link_Node current = head;
            int cnt = 0;
            while (current.nextptr != nullptr){
                cnt++;
                current = *current.nextptr;
            }
            return cnt;
        }
        // problem here! b.data -ve to get nullptr for end.
        void add_between(link_Node &a, link_Node &b, int &element){
            link_Node new_element;
            new_element.data = element;
            *new_element.nextptr = b;
            if (b.data < 0){
                new_element.nextptr = nullptr;
            }
            a.nextptr = &new_element;
            data.push_back(new_element);
        }
        void set_head(int element){
            head.data = element;
        }
        link_Node get_head(){
            return head;
        }
};
int main(){
    linkedlist linklist;
    linklist.set_head(1);
    link_Node settermtonull = {-1, nullptr};
    link_Node head = linklist.get_head();
    int a = 2;
    linklist.add_between(head, settermtonull, a);
    link_Node second = *head.nextptr;
    a = 3;
    linklist.add_between(second, settermtonull, a);
    linklist.print();
    cout << endl << linklist.size();
    cout << endl << linklist.search(5);
}