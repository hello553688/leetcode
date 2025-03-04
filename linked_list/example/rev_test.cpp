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
    ListNode* reverseList(ListNode* head) {
        ListNode* node=nullptr;
        ListNode* prev=nullptr;
        while(head != nullptr){
            node=head;
            head=head->next;
            node->next=prev;
            prev=node;
        }
        return prev;
    }
};

int main(){
    ListNode* head(nullptr);
    vector<int> data={1,2,3,4,5,6,7,8};
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