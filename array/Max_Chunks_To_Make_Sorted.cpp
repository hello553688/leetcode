#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <cmath>

using namespace std;
/*-----題目----------------------------------------------------------------
You are given an integer array arr of length n that represents a permutation of the integers in the range [0, n - 1].

We split arr into some number of chunks (i.e., partitions), and individually sort each chunk. After concatenating them
, the result should equal the sorted array.

Return the largest number of chunks we can make to sort the array.
-------------------------------------------------------------------------*/

//---看過答案
//---題目解析:由左至右檢查，若檢查數值中的最大值剛好=index的話，代表能分割一次
//---因為代表前面的的數字能通過排序成功形成一個區塊
//---1,0,2,3,4->index=1,max=1,->0,1|2,3,4->index=2,max=2,->0,1|2|3,4->...
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int chunks = 0, cur_max = 0;
        for (int i = 0; i < arr.size(); ++i) {
            cur_max = max(cur_max, arr[i]);
            if (cur_max == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};

int main(){
    vector<int> arr ={4,3,2,1,0};
    Solution a;
    int ans=a.maxChunksToSorted(arr);
    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}