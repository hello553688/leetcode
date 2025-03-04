//234. Palindrome Linked List(easy)
//Linked List,Two Pointers, Stack, recursion
//leetcode sol 
//https://leetcode.com/problems/palindrome-linked-list/solutions/3307045/3-approaches-step-by-step-don-t-need-any-other-solution-after-watching-this/

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

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* rev=nullptr;
        ListNode* next=nullptr;
        vector<int> val;
        int index=0;
        while (head!=nullptr){
            next=head->next;
            head->next=rev;
            rev=head;
            head=next;
            val.push_back(rev->val);
        }
        while (rev!=nullptr){
            if(rev->val!=val[index]){
                return false;
            }
            rev=rev->next;
            index++;
        }
   
        return true;
    }
};


//---leetcode sol
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         if(head == NULL || head->next == NULL){
//             return (head);
//         }
//         ListNode *r_head = NULL;
//         ListNode *ptr = head;
//         while(ptr!=NULL){//Reverse the list with new memory
//             ListNode *temp = new ListNode(ptr->val);
//             temp ->next = r_head;
//             r_head = temp;
//             ptr = ptr->next;
//         }
//         while(head && r_head){
//             if(head->val != r_head->val){
//                 return false;
//             }
//             head = head->next;
//             r_head = r_head->next;
//         }
//         return true;
//     }
// };

int main(){
    ListNode* head(nullptr);
    vector<int> data={1,2};
    for(int i=0;i<data.size();i++){
        insert(head,data[i]);
    }
    std::cout << "Linked List: ";
    print(head);

    Solution a;
    bool ans=a.isPalindrome(head);

    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}