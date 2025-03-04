//2022. Convert 1D Array Into 2D Array (easy)

//566. Reshape the Matrix (easy)

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
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int r=0,c=0;
        //leetcode sol
        // if(original.size()==(m*n)){
        //     vector<vector<int>> ans(m,vector<int>(n));
        //     for (int i = 0; i < original.size(); i++){
        //         ans[i/n][i%n]=original[i];
        //     }  
        //     return ans;
        // }
        if(original.size()==(m*n)){
            vector<vector<int>> ans(m,vector<int>(n));
            for (int i = 0; i < original.size(); i++){
                ans[r][c]=original[i];
                if(c==n-1){
                    c=0;
                    r++;
                }
                else{
                    c++;
                }
            }  
            return ans;
        }
        else{
            vector<vector<int>> ans;
            return ans;
        }
        
    }
};
// leetcode sol
//https://leetcode.com/problems/convert-1d-array-into-2d-array/discuss/1500530/Short-and-Self-Explanatory-or-2-Approaches-or-C%2B%2B-or-Beginner-friendly
int main(){
    vector<vector<int>> mat  = {{1,2},{3,4}};
    vector<int> original ={1,2,3,4};
    int m=2,n=2;

    Solution a;
    vector<vector<int>> ans=a.construct2DArray (original, m, n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<',';
        }
        cout<<endl; 
    }
    cout<<"end"<<endl;
    return 0;
}