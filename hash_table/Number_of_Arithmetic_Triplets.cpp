//2367. Number of Arithmetic Triplets(easy)
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
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans=0;
        unordered_map<int,int>umap;
        for(int i=0;i<nums.size();i++){
            umap.insert({nums[i],i});
        }
        for(int i=0;i<nums.size();i++){
            int p1=nums[i]+diff;
            int p2=nums[i]+diff*2;
            if(umap[p1] && umap[p2]){//直接判斷存不存在(inspire by leetcode sol)
                ans++;
            }
            // if(umap.find(p1)!=umap.end() && umap.find(p2)!=umap.end()){
            //     ans++;
            // }
        }
        return ans;
    }
};
//---leetcode sol
//---https://leetcode.com/problems/number-of-arithmetic-triplets/solutions/2392136/c-easy-hashmap-solution-with-explanation/
int main(){
    vector<int> nums = {4,5,6,7,8,9};
    int diff=2;
    Solution a;
    int ans=a.arithmeticTriplets(nums,diff);
    cout<<"ans:"<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}