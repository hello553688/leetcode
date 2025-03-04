//14. Longest Common Prefix (easy)
//205. Isomorphic Strings(easy)

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        for (size_t i = 0; i < strs[0].length(); i++){
            for (size_t j = 1; j < strs.size(); j++){
                if(i<strs[j].length()){
                    if(strs[j][i]!=strs[0][i]){
                        return ans;
                    }
                }
                else{
                    return ans;
                }
            }
            ans+=strs[0][i];
        }
        return ans;
    }
};

int main(){
    vector<string> strs={"flower","flow","flight"};
    Solution a;
    string ans=a.longestCommonPrefix(strs);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}