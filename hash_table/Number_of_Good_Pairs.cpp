//1512. Number of Good Pairs(easy)

#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<algorithm>
using namespace std;

// me:brute force time complex:O(n^2) 
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;        
        for(int i=0;i<nums.size();i++){
            for(int j=nums.size()-1;j>=i+1;j--){
                if(nums[i]==nums[j]){
                    ans++;
                }
            }
        }
        return ans;  
 
    }
};

//leetcode sol:hash map time complex:O(n^2) 
//https://leetcode.com/problems/number-of-good-pairs/solutions/4122829/brute-force-to-optimal-beats-100-with-explanation/
// class Solution {
// public:
//     int numIdenticalPairs(vector<int>& nums) {
//         unordered_map<int,int> umap;
//         int ans=0;      
        
//         for(int i=0;i<nums.size();i++){
//             if(umap[nums[i]]){
//                 ans+=umap[nums[i]];
//             }
//             umap[nums[i]]++;
//         } 

//         return ans;  

        
//     }
// };

int main(){
    vector<int> nums = {1,1,1,1};
    Solution a;
    int ans=a.numIdenticalPairs(nums);

    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}

