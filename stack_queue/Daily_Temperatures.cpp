//---739.Daily Temperatures
#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <stack>

using namespace std;

//monotonic stack 看過較有效率的寫法 
//---stack 為儲存當前日期，若遇到較大的溫度的日期，則當前日期-原日期=需要天數
class Solution {
    public:
        stack<int> date; 
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            vector<int> day(temperatures.size());
            for(int i=0;i<temperatures.size();i++){                 
                while (date.size() > 0 && temperatures[date.top()] < temperatures[i]) {
                    day[date.top()]=i-date.top();//
                    date.pop();
                }  
                date.push(i);     
            }
            return day;
        }
};

int main(){
    vector<int> temperatures  = {55,38,53,81,61,93,97,32,43,78};
    // vector<int> temperatures  = {73,74,75,71,69,72,76,73};
    Solution a;
    vector<int> ans=a.dailyTemperatures(temperatures);
    for(int i=0;i<ans.size();i++){
        cout<<"ans"<<"["<<i<<"]:"<<ans[i]<<endl;
    }
    cout<<"end"<<endl;
    return 0;
}

//---time exceed-----------------------------------------------------
// class Solution {
//     public:
//         stack<int> future_temp; 
//         stack<int> date; 

//         int d=0,cnt=0,limit;
//         vector<int> dailyTemperatures(vector<int>& temperatures) {
//             vector<int> day(temperatures.size());
//             for(int i=0;i<temperatures.size();i++){                 
//                 while (date.size() > 0 && temperatures[date.top()] < temperatures[i]) {
//                     d=i-date.top();
//                     date.pop();
//                     if(date.empty()){
//                         day[cnt]=d;
//                         i=i-(d-1);
//                         cnt++;
//                         d=0;
//                     }
                   
//                 }       
//                 if(date.empty()){
//                    date.push(i); 
//                    limit=temperatures.size()-1-i;
//                 }
//                 else if(date.size()==1 && i==temperatures.size()-1){
//                     i=i-limit;
//                     cnt++;
//                     date.pop();
//                     // cout<<"date.pop()"<<endl;
//                 }
//                 // cout<<"i:"<<i<<endl;
//                 // cout<<"d:"<<d<<endl;
//                 // cout<<"date.top():"<<date.top()<<endl;
//                 // cout<<"date.size():"<<date.size()<<endl;
//                 // cout<<endl;
               


//             }
//             return day;
//         }
// };

// class Solution {
//     public:
//         stack<int> future_temp; 
//         vector<int> day;
//         int d=0;
//         vector<int> dailyTemperatures(vector<int>& temperatures) {
//             for(int i=0;i<temperatures.size();i++){
//                 for(int j=i;j<temperatures.size();j++){
//                     if(future_temp.empty()){
//                         future_temp.push(temperatures[j]);
//                     }
//                     else{
//                         if(temperatures[j]>future_temp.top()){
//                             d++;
//                             break;
//                         }
//                         else{
//                             d++;
//                             if(d==(temperatures.size()-1-i)){
//                                 d=0;
//                             }
//                         }
//                     }
//                 }
//                 future_temp.pop();
//                 day.push_back(d);
//                 d=0;
//             }
//             return day;
//         }
// };