//160. Intersection of Two Linked Lists(easy)
//Linked List recursion
//leetcode sol https://leetcode.com/problems/intersection-of-two-linked-lists/solutions/4020914/two-pointer-solution/

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *ha,*hb;       
        if (headA == nullptr || headB == nullptr) {
            return 0;
        }
        else if(headA==headB){
            return headA;
        }
    
        ha=headA;
        hb=headB;
 
        while(headA!=nullptr && headB!=nullptr){
            if(headA==headB){
                return headA;
            }
           
            headA=headA->next;
            headB=headB->next;
            if(headA==nullptr && headB!=nullptr){   
                headA=ha;
            }
            if(headA!=nullptr && headB==nullptr){   
                headB=hb;
            }
            
        }
        return 0;
    }
};

//---leetcode 101
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *ha,*hb;       
//         if (headA == nullptr || headB == nullptr) {
//             return 0;
//         }
//         else if(headA==headB){
//             return headA;
//         }
    
//         ha=headA;
//         hb=headB;

//         while(ha!=hb){

//             ha= ha==nullptr?headA:ha->next;
//             hb= hb==nullptr?headB:hb->next;

//         }
//         return ha;
//     }
// };
int main(){
    ListNode* headA(nullptr);
    ListNode* headB(nullptr);
    ListNode* headC(nullptr);

    vector<int> data_A={1,9,1};
    vector<int> data_B={3};
    vector<int> data_C={2,4};
    for(int i=0;i<data_A.size();i++){
        insert(headA,data_A[i]);
    }
    for(int i=0;i<data_B.size();i++){
        insert(headB,data_B[i]);
    }
    for(int i=0;i<data_C.size();i++){
        insert(headC,data_C[i]);
    }
    ListNode* node_A=headA,*da=node_A;
    ListNode* node_B=headB,*db=node_B;
    while(da!=nullptr){
        if(da->next==nullptr){
            da->next=headC;
            break;
        }
        da=da->next;
    }
    while(db!=nullptr){
        if(db->next==nullptr){
            db->next=headC;
            break;
        }
        db=db->next;
    }
    std::cout << "Linked List A: ";
    print(node_A);
    std::cout << "Linked List B: ";
    print(node_B);
    // std::cout << "Linked List C: ";
    // print(headC);
    // while(node_A!=nullptr){
    //     cout<<"node_A->next: "<<node_A->next<<endl;
    //     node_A=node_A->next;
    // }
    // while(node_B!=nullptr){
    //     cout<<"node_B->next: "<<node_B->next<<endl;
    //     node_B=node_B->next;
    // }
    

    Solution a;
    ListNode* ans=a.getIntersectionNode(headA,headB);
    std::cout << "Linked List(ans): ";
    print(ans);
    // cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}