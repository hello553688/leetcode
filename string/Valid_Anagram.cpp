//242. Valid Anagram (easy)

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

//leetcode sol
//https://leetcode.com/problems/valid-anagram/solutions/4410440/beats-100-explained-with-video-hashing-c-java-python-js-visualized/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            if(s.length()!=t.length()){
                return false;
            }
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            for(int i=0;i<s.length();i++){
                if(s[i]!=t[i]){
                    return false;
                }
            }
            return true;
        }
};

int main(){
    string s="anagram";
    string t="nagaram";
    Solution a;
    bool ans=a.isAnagram(s,t);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}