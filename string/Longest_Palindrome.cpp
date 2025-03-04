//409. Longest Palindrome(easy)
//Hash Table, string, greedy
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;
//leetcode sol
//https://leetcode.com/problems/longest-palindrome/solutions/3156147/c-easiest-beginner-friendly-sol-o-n-time-and-o-128-o-1-space/

class Solution {
    public:
        int longestPalindrome(string s) {
            int ans=0,odd=-1;//odd=-1代表我最後一定要拿一個基數來滿足回文
            vector<int> ch_map(52,0);
            for(int i=0;i<s.length();i++){
                int index=s[i]-'a'<0?s[i]-'A':26+s[i]-'a';
                ch_map[index]++;     
            }
            for(int i=0;i<ch_map.size();i++){
                if(ch_map[i] % 2!=0){
                    odd++;
                }
            }
            if(odd==-1){//if not even,odd=0
                odd=0;
            }
            return s.length()-odd;
        }
};

int main(){
    string s="abccccdd";
    Solution a;
    int ans=a.longestPalindrome(s);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}