//206. Reverse Linked List(easy)
//Linked List,Recursion
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;


//----definition for singly-linked list---------------------------
struct ListNode {
    int val;
    ListNode *next;
    // Constructor
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// Insert node at the end
void insert(ListNode* &head,int val) {
    ListNode* newNode = new ListNode(val);
    if (head == nullptr) {
        head = newNode;
    } 
    else {
        ListNode* current = head;
        while (current->next != nullptr) { //如果不是最後，則移動 Insert node at the end
            current = current->next;
        }
        current->next = newNode;
    }
}
// Remove node with specified value
void remove(ListNode* &head,int value) {
    ListNode* current = head;
    ListNode* prev = nullptr;//尋找待刪除node的前一個node

    while (current != nullptr) {
        if (current->val == value) {
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
void print(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr) {
            std::cout << current->val << " ";
            current = current->next;
        }
        std::cout << std::endl;
}
//---------------------------------------------------------------
//reverse linked list vid:https://www.youtube.com/watch?v=VtC4GUR31wQ

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        while(head!=nullptr){
            next=head->next;
            head->next=prev;
            prev=head;
            head=next;
            std::cout << "prev List: ";
            print(prev);
            // std::cout << "next List: ";
            // print(next);
        }
        return prev;
    }
};
//leetcode 101 sol
//recursion solution
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head, ListNode* prev=nullptr) {
//         if (!head) {
//             return prev;
//         }
//         ListNode* next = head->next;
//         head->next = prev;
//         return reverseList(next, head);
//     }
// };

int main(){
    ListNode* head(nullptr);
    vector<int> data={1,2,3};
    for(int i=0;i<data.size();i++){
        insert(head,data[i]);
    }
    std::cout << "Linked List: ";
    print(head);
    Solution a;
    ListNode* ans=a.reverseList(head);
    std::cout << "Linked List(ans): ";
    print(ans);
    // cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}