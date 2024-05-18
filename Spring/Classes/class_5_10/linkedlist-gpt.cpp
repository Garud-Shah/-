// I didn't know how to do this code, since I did not how how to perform dynamic memory allocation 
// for a list of elements. I used ChatGPT to learn what a destructor is. It mostly kept my code the
// same, but changed it to use pointers instead of normal variables. This is because I was building a
// linked list class. I wanted to bui
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct link_Node {
    double data;
    link_Node* nextptr;
};

class linkedlist {
    private:
        unordered_set<link_Node*> data; // Store pointers to dynamically allocated nodes
        link_Node* head = nullptr;
        // sz keeps track of size during inserts and deletes.
        int sz = 1;
    public:
        // Destructor to deallocate memory
        ~linkedlist() {
            for (auto node : data){
                delete node;
            }
        }

        // Print the linked list
        void print() const {
            link_Node* current = head;
            while (current != nullptr){
                cout << current->data << " ";
                current = current->nextptr;
            }
            cout << endl;
        }

        // Search for an element in the linked list
        bool search(double element){
            link_Node* current = head;
            while (current != nullptr){
                if (current->data == element){
                    return true;
                }
                current = current->nextptr;
            }
            return false;
        }
        
        // Get the head of the linked list
        link_Node* get_head(){
            return head;
        }
        // Calculate the size of the linked list
        int size(){
            return sz;
        }

        // Add a new element after a specified node
        void add_after(link_Node* before, double element){
            link_Node* new_element = new link_Node{element, before->nextptr};
            before->nextptr = new_element;
            data.insert(new_element);
            sz++;
        }

        // Remove a specified node
        void remove(link_Node* a, link_Node* previous){
            if (previous != nullptr) {
                previous->nextptr = a->nextptr;
            } else {
                head = a->nextptr;
            }
            data.erase(a);
            delete a;
            sz--;
        }

        // Set the head of the linked list
        void set_head(double element){
            head = new link_Node{element, nullptr};
            data.insert(head);
        }

        // Convert a vector to a linked list
        void v_convert(vector<double> values){
            bool check = false;
            link_Node* previous;
            for (auto i: values){
                if (!check){
                    set_head(i);
                    check = true;
                    previous = get_head();
                    continue;
                }
                add_after(previous, i);
                previous = previous -> nextptr;
            }
        }
};

int main() {
    linkedlist linklist;
    linklist.v_convert({1, 2, 3});
    linklist.print();
    cout << linklist.search(5) << endl;
    cout << linklist.size() << endl;
}
