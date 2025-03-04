//696. Count Binary Substrings(easy)

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;
//leetcode
//https://leetcode.com/problems/count-binary-substrings/solutions/1172569/short-easy-w-explanation-comments-keeping-consecutive-0s-and-1s-count-beats-100/


//--tow pointer
class Solution {
    public:
        int countBinarySubstrings(string s) {
            int ans=0;
            int p0,p1;
            for(int i=0;i<s.length()-1;i++){
                if(s.length()==1){
                    return ans;
                }
                p0=i;
                p1=i+1;
                if(s[p0]!=s[p1]){
                    char c0=s[p0];
                    char c1=s[p1];
                    ans++;
                    p0--;
                    p1++;
                    while(p0>=0 && p1<s.length()){
                        if(s[p0]==c0 && s[p1]==c1){
                            ans++;
                        }
                        else{
                            break;
                        }
                        p0--;
                        p1++;
                    }
                }
            }
            return ans;
        }
};

int main(){
    string s="00110011";
    Solution a;
    int ans=a.countBinarySubstrings(s);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}