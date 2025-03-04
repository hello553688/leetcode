#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Insert node at the end
    void insert(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            cout<<"head->data:"<<head->data<<endl;
            cout<<"head->next:"<<head->next<<endl;
            cout<<endl;
        } 
        else {
            Node* current = head;
            while (current->next != nullptr) { //如果不是最後，則移動 Insert node at the end
                cout<<"current->next != nullptr"<<endl;
                current = current->next;
            }
            current->next = newNode;
            cout<<"current->data:"<<current->data<<endl;
            cout<<"current->next:"<<current->next<<endl;
            cout<<endl;

        }
    }
    // Remove node with specified value
    void remove(int value) {
        Node* current = head;
        Node* prev = nullptr;//尋找待刪除node的前一個node

        while (current != nullptr) {//check linked list裡面有node
            if (current->data == value) {
                if (prev == nullptr) {//if current is the first element
                    head = current->next;
                } 
                else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }
    // Print the linked list
    void print() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    // Create a linked list object
    LinkedList list;

    // Insert nodes
    list.insert(1);
    list.insert(2);
    list.insert(3);

    // Print the linked list
    std::cout << "Linked List: ";
    list.print();

    // Remove node with value 2
    list.remove(2);

    // Print the modified linked list
    std::cout << "Modified Linked List: ";
    list.print();

    return 0;
}