#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;

//---me
class Solution {
    public:
        vector<int> findDisappearedNumbers(vector<int>& nums) {
            vector<int> temp(nums.size());
            vector<int> result;
            for(int i=0;i<nums.size();i++){
                temp[nums[i]-1]=nums[i];//�Nnums[i]���쥻��index
            }
            for(int i=0;i<temp.size();i++){
                if(temp[i]==0){
                    result.push_back(i+1);
                }
            }
            return result;
        }
};

//----leetcode101 book
// class Solution {
//     public:
//         vector<int> findDisappearedNumbers(vector<int>& nums) {
//             vector<int> ans;
         
//             for (const int &num : nums) {
//                 int pos=abs(num)-1;
//                 if(nums[pos]>0){
//                     nums[pos] = -nums[pos];
//                 }
//             }
//             for(int i=0;i<nums.size();i++){
//                 if(nums[i]>0){
//                     ans.push_back(i+1);
//                 }
//             }
//             return ans;
//         }
// };

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};//
    Solution a;
    vector<int> result=a.findDisappearedNumbers(nums);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}