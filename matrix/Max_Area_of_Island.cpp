//695. Max Area of Island(medium)
//see ans :(

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
    int dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(i>=0 && i<m && j>=0 && j<n && grid[i][j]==1){
            grid[i][j]=0;
            return 1+dfs(grid,i+1,j,m,n)+dfs(grid,i-1,j,m,n)+dfs(grid,i,j+1,m,n)+dfs(grid,i,j-1,m,n);
        } 
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0,cnt=0;
        int row=grid.size();
        int col=grid[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    cnt=dfs(grid,i,j,row,col);
                } 
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};

//leetcode sol 
//https://leetcode.com/problems/max-area-of-island/discuss/1610488/C%2B%2Boror-Easy-to-UnderstandororDFS
int main(){
    vector<vector<int>> grid  = {
    {0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};

    Solution a;
    int ans=a.maxAreaOfIsland(grid);
    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}