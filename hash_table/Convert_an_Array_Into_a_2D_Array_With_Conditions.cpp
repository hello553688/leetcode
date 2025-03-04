//2610. Convert an Array Into a 2D Array With Conditions(meduim)
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
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int> umap;//num,cnt
        vector<vector<int>>ans;
        int all_zero=0,size=0;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        // for (auto x : umap){
        //     cout << x.first << " " <<  
        //     x.second << endl;
        // }
        size = umap.size();
        while (all_zero < size){
            vector<int> temp;
            all_zero=0;
            for(auto x : umap){
                if(x.second>0){
                    temp.push_back(x.first);
                    umap[x.first]--;  
                }  
                else{
                    all_zero++;
                }
            }
            if(all_zero < size){
                ans.push_back(temp);  
            }   
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {1,3,4,1,2,3,1};

    Solution a;
    vector<vector<int>> ans=a.findMatrix(nums);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<',';
        }
        cout<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}