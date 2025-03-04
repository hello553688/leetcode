//28. Find the Index of the First Occurrence in a String(easy)
//leetcode sol (KMP Algorithm)
//https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/4673241/video-visualization-of-o-n-kmp-algorithm/

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
    public:
        int strStr(string haystack, string needle) {
            int j=1,index=-1;
            if(haystack.length()<needle.length()){
                return index;
            }
            for(int i=0;i<haystack.length()-(needle.length()-1);i++){
                if(haystack[i]==needle[0]){
                    while(j<needle.length()){
                        if(haystack[i+j]!=needle[j]){
                            break;
                        }
                        j++;
                    }
                    if(j==needle.length()){
                        index=i;
                        return index;
                    }
                    else{
                        j=0;
                    }
                }
            }
            return index;
        }
};

int main(){
    string haystack="bcxabaaac";
    string needle="abaaa";
    Solution a;
    int ans=a.strStr(haystack,needle);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}