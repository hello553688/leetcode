//21. Merge Two Sorted Lists
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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1=list1;
        ListNode* h2=list2;
        
        ListNode* node=new ListNode(0);
        ListNode* ans=node;
        while (h1!=nullptr && h2!=nullptr){
            if(h1->val<=h2->val){
                node->next=h1;
                h1=h1->next;
            }
            else{
                node->next=h2;
                h2=h2->next;
            }
            node=node->next;
        }
        node->next=h1? h1:h2;  
        // print(ans);
        return ans->next;
    }
};
//---------------------------------------------------------------
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* head=nullptr;
//         ListNode* ans =nullptr;
//         ListNode* h1=list1;
//         ListNode* h2=list2;
//         if(!(h1) && (h2) ){
//             ans=h2;
//             return ans;
//         }
//         else if((h1) && !(h2)){
//             ans=h1;
//             return ans;
//         }
//         while(h1!=nullptr || h2!=nullptr){
//             if(h1->val<h2->val){
//                 insert(head,h1->val);
//                 if(!ans){
//                     ans=head;
//                 }
//                 h1=h1->next;
//                 // print(ans);
                
//             }
//             else if(h1->val>h2->val){
//                 insert(head,h2->val);
//                 if(!ans){
//                     ans=head;
//                 }
//                 h2=h2->next;
//                 // print(ans);
//             }  
//             else{
//                 insert(head,h1->val);
//                 if(!ans){
//                     ans=head;
//                 }
//                 insert(head,h2->val);
//                 h1=h1->next;
//                 h2=h2->next;
//                 // print(ans);
//             }
//             while(h1!=nullptr && h2==nullptr){
//                 insert(head,h1->val);
//                 h1=h1->next;
//             }
//             while(h1==nullptr && h2!=nullptr){
//                 insert(head,h2->val);
//                 h2=h2->next;
//             }
            
//         }
//         return ans;
//     }
// };


int main(){
    ListNode* list1 = nullptr;
    ListNode* list2 = nullptr;
    vector<int> data_1={1,2,4};
    vector<int> data_2={1,3,4};
    for(int i=0;i<data_1.size();i++){
        insert(list1,data_1[i]);
    }
    for(int i=0;i<data_2.size();i++){
        insert(list2,data_2[i]);
    }
    std::cout << "list1: ";
    print(list1);
    std::cout << "list2: ";
    print(list2);
    Solution a;
    ListNode* ans=a.mergeTwoLists(list1,list2);
    std::cout << "Linked List(ans): ";
    print(ans);
    
    cout<<"end"<<endl;
    return 0;
}