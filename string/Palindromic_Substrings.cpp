//647. Palindromic Substrings(Medium)
//string, Dynamic Programming
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        int countSubstrings(string s) {
            string sub_s="";
            int ans=0;
            for(int n=0;n<s.length();n++){
               for(int i=1+n;i<s.length();i++){
                    for(int j=n;j<=i;j++){
                        sub_s+=s[j];
                    }
                    // cout<<"sub_s:"<<sub_s<<endl;
                    string str_rev=sub_s;
                    reverse(str_rev.begin(),str_rev.end());
                    if(sub_s==str_rev){
                        ans++;
                    }
                    sub_s="";
                }
            }
            
            return ans+s.length();
        }
};

// leetcode DP sol
// https://leetcode.com/problems/palindromic-substrings/solutions/4579688/best-optimal-solution/
// leetcode 101
// class Solution {
//     public:
//         int countSubstrings(string s) {
//             int count = 0;
//             for (int i = 0; i < s.length(); ++i) {
//                 count += extendSubstrings(s, i, i); // ©_??«×
//                 count += extendSubstrings(s, i, i + 1); // °¸??«×
//             }
//             return count;
//         }
//         int extendSubstrings(string s, int l, int r) {
//             int count = 0;
//             while (l >= 0 && r < s.length() && s[l] == s[r]) {
//                 --l;
//                 ++r;
//                 ++count;
//             }
//             return count;
//         }
// };




int main(){
    string s="ababa";
    Solution a;
    int ans=a.countSubstrings(s);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}