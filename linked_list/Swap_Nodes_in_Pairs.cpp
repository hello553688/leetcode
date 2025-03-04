//24. Swap Nodes in Pairs(medium)
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
        while (current->next != nullptr) { //�p�G���O�̫�A�h���� Insert node at the end
            current = current->next;
        }
        current->next = newNode;
    }
}
// Remove node with specified value
void remove(ListNode* &head,int value) {
    ListNode* current = head;
    ListNode* prev = nullptr;//�M��ݧR��node���e�@��node

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

// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* dummy=new ListNode(0),*node=dummy;
//         ListNode* now=head;
//         if (head == nullptr || head->next == nullptr) {
//             return head;
//         }
//         ListNode* next = head->next;

//         while (head!=nullptr){
//             //swap
//             now->next=next->next;
//             next->next=now;
            
//             node->next=next;
//             node=now;
//             head=head->next;
           
//             if(head!=nullptr){
//                 now=head;   
//                 if(now->next==nullptr){//�p�Glinked list size����ơA��̫�next�N���|����
//                     head=head->next;
//                 } 
//             }
//             if(now->next!=nullptr){   
//                 next=now->next;
//             }
          
//         }   
//         return dummy->next;   
//     }
    
// };

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(0),*node=dummy;
        ListNode* now=head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode* next;
        while (head!=nullptr){
            next=now->next;
            //swap
            now->next=next->next;
            next->next=now;

            node->next=next;
            node=node->next->next;

            head=head->next;
            now=head;
            if(now && now->next==nullptr){
                node->next=now;
                head=head->next;
            }
        }
        return dummy->next;
    }
    
};

int main(){
    ListNode* head(nullptr);
    vector<int> data={1,2,3,4};
    for(int i=0;i<data.size();i++){
        insert(head,data[i]);
    }
    std::cout << "Linked List: ";
    print(head);
    Solution a;
    ListNode* ans=a.swapPairs(head);
    std::cout << "Linked List(ans): ";
    print(ans);
    // cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}