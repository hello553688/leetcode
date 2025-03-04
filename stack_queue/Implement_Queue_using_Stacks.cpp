#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;
//leetcode sol(我認為最合理的解答)
//https://leetcode.com/problems/implement-queue-using-stacks/solutions/4641109/beats-100-users-c-java-python-javascript-explained/

//Stack就是和Queue相反
class MyQueue {
    public:
        stack<int> s1,s2;  
        MyQueue() {
           
        }
        
        void push(int x) {
            s1.push(x);
        }
        
        int pop() {
            int s1_size=s1.size();
            for(int i=0;i<s1_size;i++){
                s2.push(s1.top());        
                s1.pop();
            }
            int q_pop=s2.top();
            s2.pop();
            int s2_size=s2.size();
            for(int i=0;i<s2_size;i++){
                s1.push(s2.top());
                s2.pop();
            }
            return q_pop;
        }
        
        int peek() {
            int s1_size=s1.size();
            for(int i=0;i<s1_size;i++){
                s2.push(s1.top());        
                s1.pop();
            }
            int q_peek=s2.top();
            int s2_size=s2.size();
            for(int i=0;i<s2_size;i++){
                s1.push(s2.top());
                s2.pop();
            }
            return q_peek;
        }
        bool empty() {
            return s1.empty();
        }
};


int main(){
    MyQueue* q=new MyQueue();
    int x=1;
    q->push(1);
    q->push(2);
    int param_2 = q->pop();
    int param_3 = q->peek();
    bool param_4 = q->empty();
    cout<<"param_2:"<<param_2<<endl;
    cout<<"param_3:"<<param_3<<endl;
    cout<<"param_4:"<<param_4<<endl;

    cout<<"end"<<endl;
    return 0;
}