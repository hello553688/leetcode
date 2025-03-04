//128. Longest Consecutive Sequence(medium)
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map> 
#include<algorithm>
using namespace std;
//---這題解法基本上沒有滿足O(n)的要求

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        unordered_map<int,int> umap;
        int pre_val=0,ans=1;
        sort(nums.begin(),nums.end());
        umap.insert({nums[0], 0});
        pre_val=nums[0];
       

        for(int i=1;i<nums.size();i++){

            if(nums[i]==pre_val+1){
                umap.insert({nums[i], i});
                pre_val=nums[i];
                int map_size=umap.size();
                ans = max(ans,map_size);
            }
            else if(!umap.count(nums[i])){//check nums[i] doesnt duplicate
                int map_size=umap.size();
                ans = max(ans,map_size);
                umap.clear();
                umap.insert({nums[i], i});
                pre_val=nums[i];
            }    
            // cout<<"pre_val:"<<pre_val<<endl;
            // cout<<"ans:"<<ans<<endl;
            // cout<<endl;

        }
        return ans;
    }
};
 
int main(){
    vector<int> nums = {4,0,-4,-2,2,5,2,0,-8,-8,-8,-8,-1,7,4,5,5,-4,6,6,-3};//-8,-8,-8,-8,-4,-4,-3,-2,-1,0,0,2,2,4,4,5,5,5,6,6,7
    // sort(nums.begin(),nums.end());
    // for(int i=0;i<nums.size();i++){
    //     cout<<nums[i]<<",";
    // }
    Solution a;
    int ans=a.longestConsecutive(nums);

    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}