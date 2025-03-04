//1630. Arithmetic Subarrays
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<map> 
#include<algorithm>
#include <chrono>
#include <ctime>
#include <random>

using namespace std;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        map<int,int> arr_map;
        vector<int> temp;
        vector<bool> ans;
        for(int i=0;i<l.size();i++){
            for(int j = l[i];j < r[i]+1;j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            
            int diff=temp[1]-temp[0];
            bool res;
            for(int k=1;k<temp.size();k++){
                if((temp[k]-temp[k-1])!=diff){
                    res=false;
                    break;
                }
                else{
                    res=true;
                }
            }
            // cout<<"res:"<<res<<endl;
            ans.push_back(res);
            temp.clear();
            
        }
        return ans;
    }
};
//---leetcode sol (還沒看過)
//---https://leetcode.com/problems/arithmetic-subarrays/solutions/4319035/c-arithmetic-progression-17-ms-beats-100/

int main(){
    vector<int> nums = {-12,-9,-3,-12,-6,15,20,-25,-20,-15,-10};
    vector<int> l = {0,1,6,4,8,7};
    vector<int> r = {4,4,9,7,9,10};

    Solution a;
    vector<bool> ans=a.checkArithmeticSubarrays(nums,l,r);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}