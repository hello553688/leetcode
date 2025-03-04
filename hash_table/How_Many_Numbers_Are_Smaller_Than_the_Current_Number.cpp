//1365. How Many Numbers Are Smaller Than the Current Number(easy)
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<map> 
#include<algorithm>
#include <chrono>
#include <ctime>

using namespace std;
//----hash table-----------
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        clock_t start = clock();
        vector<int> res(nums.size());
        unordered_map<int,int> umap;
        for(int i=0;i<nums.size();i++){
            umap[nums[i]]++;
        }
        // for (auto x : umap){
        //     cout << x.first << " " <<  
        //     x.second << endl;
        // }
        for(int i=0;i<nums.size();i++){
            for (auto x : umap){
                if(x.first<nums[i]){
                    res[i]+=x.second;
                }
            }
        }

        // 計時結束
        clock_t end = clock();
        double duration = double(end - start) / CLOCKS_PER_SEC * 1000;
        cout << "執行時間: " << duration << " 毫秒" << std::endl;
        return res;
    }
};
//---leetcode(map sol:O(n))
//---https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/solutions/4719511/o-n-c-beats-96/
//----brute force-------
// for(int i=0;i<nums.size();i++){
//     for(int j=0;j<nums.size();j++){
//         if(j!=i && nums[j] < nums[i]){
//             res[i]++;
//         }
//     }
// }
int main(){
    vector<int> nums = {8,1,2,2,3};
    // vector<int> nums;
    Solution a;
    // for(int i=0;i<1000;i++){
    //     nums.push_back(i);
    // }
    vector<int> res=a.smallerNumbersThanCurrent(nums);
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}
