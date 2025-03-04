//1282. Group the People Given the Group Size They Belong To(medium)
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<map> 
#include<algorithm>
#include <chrono>
#include <ctime>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,int> data_map;//person ,size
        unordered_map<int,int> index_map;//ans index map={size,ans_index}
        vector<vector<int>> ans;
        vector<int> temp;
        int cnt=0;
        for(int i=0;i<groupSizes.size();i++){
            data_map.insert({i,groupSizes[i]});//person ,size
        }
        for(auto x:data_map){
            if(ans.empty() || !index_map.count(x.second)){//check ans.empty or 出現前面沒有的size
                ans.push_back(temp);
                index_map.insert({x.second,cnt});
                ans[index_map[x.second]].push_back(x.first);//index_map[x.second]:get ans index
                cnt++;
            }
            else if(ans[index_map[x.second]].size()==x.second){//check ans[index_map[x.second]] full or not
                ans.push_back(temp);
                index_map[x.second]=cnt;
                ans[index_map[x.second]].push_back(x.first);
                cnt++;
            }
            else{
                ans[index_map[x.second]].push_back(x.first);
            }
            
        }
        return ans;
    }
};
//---leetcode sol
//---https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/solutions/4029322/beats-99-89-with-proper-example-explanation/
int main(){
    vector<int> groupSizes = {2,1,3,3,3,2};
    Solution a;
    vector<vector<int>> ans=a.groupThePeople(groupSizes);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<',';
        }
        cout<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}