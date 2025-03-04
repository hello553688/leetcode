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
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int>(c,0));
        int row_m=mat.size();
        int col_m=mat[0].size();
        int ro=0,co=0;
        if((row_m*col_m)==(r*c)){
            for(int i=0;i<row_m;i++){
                for(int j=0;j<col_m;j++){
                   ans[ro][co]=mat[i][j];
                   if(co==c-1){
                        co=0;
                        ro++;
                   }
                   else{
                        co++;
                   }
                }
            }
        }
        else{
            return mat;
        }
        return ans;
    }
};
//leetcode sol 
//https://leetcode.com/problems/reshape-the-matrix/discuss/1317151/C%2B%2B-One-Loop-Easy-Solution-or-Column-first-and-Row-first-Approaches

int main(){
    vector<vector<int>> mat  = {{1,2},{3,4}};
    int r=4,c=1;

    Solution a;
    vector<vector<int>> ans=a.matrixReshape (mat, r, c);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<',';
        }
        cout<<endl; 
    }
    cout<<"end"<<endl;
    return 0;
}