//771. Jewels and Stones(easy)
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map> 
#include<algorithm>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int> umap;
        int ans=0;
        for(int i=0;i<jewels.length();i++){
            umap.insert({jewels[i],i});
        }
        for(int i=0;i<stones.length();i++){
            if(umap.count(stones[i])){
                ans++;
            }
        }
        return ans;
    }
};

int main(){
    string jewels="aA";
    string stones="aAAbbbb";
    Solution a;
    int ans=a.numJewelsInStones(jewels,stones);

    cout<<ans<<endl;
    cout<<"end"<<endl;
    return 0;
}
