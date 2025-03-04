//1721. Swapping Nodes in a Linked List(medium)

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0),*node=dummy;
        ListNode* now=head;
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        vector<int> arr;
        while(now){
            arr.push_back(now->val);
            now=now->next;
        }
        int temp=arr[k-1];
        arr[k-1]=arr[arr.size()-k];
        arr[arr.size()-k]=temp;
        for(int i=0;i<arr.size();i++){
            ListNode* val=new ListNode(arr[i]);
            node->next=val;
            node=node->next;
        }
        return dummy->next;
        
    }
};

int main(){
    ListNode* head(nullptr);
    vector<int> data={7,9,6,6,7,8,3,0,9,5};
    int k=5;
    for(int i=0;i<data.size();i++){
        insert(head,data[i]);
    }
    std::cout << "Linked List: ";
    print(head);
    Solution a;
    ListNode* ans=a.swapNodes(head,k);
    std::cout << "Linked List(ans): ";
    print(ans);
    // cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}