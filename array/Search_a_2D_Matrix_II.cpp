#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cmath>

using namespace std;
//array "binary search" Divide and Conquer matrix
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row=matrix.size();
            int col=matrix[0].size();
            int st_row=0;
            int st_col=col-1;
            while (st_row<row && st_col>=0){
                if(matrix[st_row][st_col]==target){
                    return true;
                }
                else{
                    matrix[st_row][st_col]<target? st_row++ : st_col--;
                }
                
            }
            return false;  
        }
};


int main(){
    // vector<vector<int>> matrix = {{-1,3}};
    vector<vector<int>> matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=0;
    Solution a;
    bool ans=a.searchMatrix(matrix,target);
    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}