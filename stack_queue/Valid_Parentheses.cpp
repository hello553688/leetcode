#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        stack<char> bracket;
        bool isValid(string s) {
            string s1="()";
            string s2="[]";
            string s3="{}";
            for(int i=0;i<s.length();i++){
                if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                    bracket.push(s[i]);
                }
                else{
                    if(!bracket.empty()){
                        //char->string
                        string str=string(1, bracket.top()) + s[i];
                        if(str==s1 ||str==s2 ||str==s3){
                            bracket.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
            
            if(bracket.empty() && s!=" "){
                return true;
            }
            return 0;
        }
};

int main(){
    string s=" ";//
    Solution a;
    bool result=a.isValid(s);
    cout<<"result:"<<result<<endl;
    cout<<"end"<<endl;
    return 0;
}