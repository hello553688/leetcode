//2325. Decode the Message
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<map> 
#include<algorithm>
#include <chrono>
#include <ctime>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        string low_letter="abcdefghijklmnopqrstuvwxyz";
        string ans;
        int cnt=0;
        unordered_map<char,char> umap;
        for(int i=0;i<key.length();i++){
            if(key[i]!=' '){
                if(!umap.count(key[i])){
                    umap.insert({key[i], low_letter[cnt]});
                    cnt++;
                }
            }
            else if(cnt==26){
                break;
            }
        }
        for(int i=0;i<message.length();i++){
            if(message[i]!=' '){
                ans+=umap[message[i]];
            }
            else{
                ans+=' ';
            }    
        }
        return ans;
    }
};

int main(){
    string key="eljuxhpwnyrdgtqkviszcfmabo";
    string message="zwx hnfx lqantp mnoeius ycgk vcnjrdb";
    Solution a;
    string res=a.decodeMessage(key,message);
   
    cout<<"res:"<<res<<endl;
    cout<<"end"<<endl;
    return 0;
}