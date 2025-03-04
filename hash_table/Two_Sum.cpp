//1. Two Sum(easy)
#include<iostream>
#include<vector>
#include<string>
#include <unordered_map> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap;
        vector<int> res(2);
        // for(int i=0;i<nums.size();i++){
        //     umap.insert({ nums[i], i});
        // }
        for(int i=0;i<nums.size();i++){
            umap.insert({ nums[i], i});
            int find_num = target-nums[i];
            if (umap.count(find_num) && umap[find_num]!=i){
                res[0]=i;
                res[1]=umap[find_num];
                return res;
            }
        }
        return res;
    }
};

int main(){
    vector<int> nums = {3,3};
    int target=6;
    Solution a;
    vector<int> twoSum_result=a.twoSum(nums,target);
    for(int i=0;i<twoSum_result.size();i++){
        cout<<twoSum_result[i]<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}



