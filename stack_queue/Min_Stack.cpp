//155. Min Stack (easy)
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

class MinStack {
    public:
        stack<int>s1,min_st;
        MinStack() {
            
        }
        
        void push(int val) {
            s1.push(val);
            if(min_st.empty()){
                min_st.push(val);
            }
            else{
                if(val<=min_st.top()){
                    min_st.push(val);
                }
            }
        }
        
        void pop() {
            if(s1.top()==min_st.top()){
                min_st.pop();
            }
            s1.pop();
        }
        
        int top() {
            return s1.top();
        }
        
        int getMin() {
            return min_st.top();      
        }
};

int main(){
    MinStack* s=new MinStack();
    s->push(-1);
    s->push(-2);
    s->push(-3);
    int param_4 = s->getMin();
    cout<<"getMin:"<<param_4<<endl;

    s->pop();
    int param_3 = s->top();
    cout<<"s->top():"<<param_3<<endl;

    param_4 = s->getMin();
    cout<<"getMin:"<<param_4<<endl;

    cout<<"end"<<endl;
    return 0;
}