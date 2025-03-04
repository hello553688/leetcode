#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cmath>

using namespace std;


/*rot_mat=[cosd(delta),-sind(delta);
            sind(delta),cosd(delta)];*/
class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            //---transpose matrix----------------
            //---–Ω常ㄌ癸à絬ユ传じ:(0,1)<->(1,0),(0,2)<->(2,0)...
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = i + 1; j < matrix[i].size(); j++) {
                    // Swap matrix[i][j] and matrix[j][i]
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
                }
            }
            int n=matrix.size();
            int last_col=matrix.size()-1;
            int first_col=0;
            //---swap col value----------------
            //---ㄌよ皚ㄓ∕﹚ユ传Ω计:(n/2)Ω
            //----キ描钩 reverse vector----------------------
            for(int k=0;k<(n/2);k++){
                for(int i=0;i<n;i++){//row
                    int temp = matrix[i][first_col];
                    matrix[i][first_col] = matrix[i][last_col];
                    matrix[i][last_col] = temp;
                }
                last_col--;
                first_col++;
            }
            
        }
};


//----------------------------------------------------
/*
 * clockwise rotate
 * first reverse up to down, then swap the symmetry 
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
*/
// void rotate(vector<vector<int> > &matrix) {
//     reverse(matrix.begin(), matrix.end());
//     for (int i = 0; i < matrix.size(); ++i) {
//         for (int j = i + 1; j < matrix[i].size(); ++j)
//             swap(matrix[i][j], matrix[j][i]);
//     }
// }
//----------------------------------------------------

int main(){
    // vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};

    Solution a;
    a.rotate(matrix);
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size();j++){
            cout<<matrix[i][j]<<',';
        }
        cout<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}