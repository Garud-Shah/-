// GSGPT Libary - Linked List
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
    public:
        // Destructor to deallocate memory
        ~linkedlist() {
            for (auto node : data) {
                delete node;
            }
        }

        // Print the linked list
        void print(){
            link_Node* current = head;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->nextptr;
            }
            cout << endl;
        }

        // Search for an element in the linked list
        bool search(double element){
            link_Node* current = head;
            while (current != nullptr) {
                if (current->data == element) {
                    return true;
                }
                current = current->nextptr;
            }
            return false;
        }

        // Calculate the size of the linked list
        int size(){
            return data.size();
        }

        // Add a new element after a specified node
        void add_after(link_Node* before, double element) {
            link_Node* new_element = new link_Node{element, before->nextptr};
            before->nextptr = new_element;
            data.insert(new_element);
        }

        // Remove a specified node
        void remove(link_Node* a, link_Node* previous) {
            if (previous != nullptr) {
                previous->nextptr = a->nextptr;
            } else {
                head = a->nextptr;
            }
            data.erase(a);
            delete a;
        }

        // Set the head of the linked list
        void set_head(double element) {
            head = new link_Node{element, nullptr};
            data.insert(head);
        }

        // Get the head of the linked list
        link_Node* get_head(){
            return head;
        }

        // Append element to the linked list
        void append(double element){
            if (head == nullptr){
                set_head(element);
            } else {
                link_Node* new_element = new link_Node{element, nullptr};
                data.insert(new_element);
            }
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
        
        // Operator + to combine two linked lists
        linkedlist operator+(linkedlist& other){
            linkedlist result;

            // Copy the current list to result
            link_Node* current = head;
            while (current != nullptr) {
                result.append(current->data);
                current = current->nextptr;
            }

            // Copy the other list to result
            current = other.head;
            while (current != nullptr) {
                result.append(current->data);
                current = current->nextptr;
            }
            return result;
    }
};

int main() {
    linkedlist linklist1;
    linklist1.v_convert({1, 2, 3});
    linklist1.print(); // Should print 1 2 3

    linkedlist linklist2;
    linklist2.v_convert({4, 5, 6});
    linklist2.print(); // Should print 4 5 6

    linkedlist combined = linklist1 + linklist2;
    combined.print(); // Should print 1 2 3 4 5 6

    return 0;
}
