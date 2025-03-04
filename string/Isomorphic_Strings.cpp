//205. Isomorphic Strings(easy)

#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

//s_index,t_index:char
//s_map[s_index],t_map[t_index]:pos
class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            vector<int> s_map(256,-1);
            vector<int> t_map(256,-1);
            for(int i=0;i<s.length();i++){
                int s_index=s[i];
                int t_index=t[i];

                if(s_map[s_index]>=0 && t_map[t_index]>=0){
                    if(s_map[s_index]==t_map[t_index]){
                        // cout<<"i:"<<i<<endl;
                        // cout<<"s_map[s_index]:"<<s_map[s_index]<<endl;
                        // cout<<"t_map[t_index]:"<<t_map[t_index]<<endl;
                        s_map[s_index]=i;
                        t_map[t_index]=i;
                        
                    }
                    else{
                        return false;
                    }
                }
                else{
                    if(s_map[s_index]<0 && t_map[t_index]<0){
                        s_map[s_index]=i;
                        t_map[t_index]=i;
                    }
                    else{
                        return false;
                    }
                }     
                
            }
            return true;
        }
};
//leetcode 101 book
// class Solution {
//     public:
//         bool isIsomorphic(string s, string t) {
//             vector<int> s_first_index(256, 0), t_first_index(256, 0);
//             for (int i = 0; i < s.length(); ++i) {
//                 if (s_first_index[s[i]] != t_first_index[t[i]]) {
//                     return false;
//                 }
//                 s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
//             }
//             return true;
//         }
// };
int main(){
    string s="egg";
    string t="foo";
    Solution a;
    bool ans=a.isIsomorphic(s,t);
    cout<<"ans:"<<ans<<endl; 
    cout<<"end"<<endl;
    return 0;
}