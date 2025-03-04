#include<iostream>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;
class Solution {
public:
    void selection_sort(vector<int>& nums) {
        int min_val=0,index=0;
        for(int i=0;i<nums.size()-1;i++){
            index=i;
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]<nums[index]){
                    index=j;
                }
            }    
            if (index != i){//dont swap same pos
                swap(nums[i],nums[index]);
            } 
            
        }
    }
    void bubble_sort(vector<int>& nums) {      
        for(int i=0;i<nums.size()-1;i++){
            for(int j=1;j<nums.size()-i;j++){
                if(nums[j-1]>nums[j]){
                    swap(nums[j-1],nums[j]);
                }
            }
            
        }
    }
    void insertion_sort(vector<int>& nums) {      
        for(int i=1;i<nums.size();i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]>nums[j+1]){
                    swap(nums[j],nums[j+1]);
                }
                else{
                    break;
                }
            }
        }
    }
    int partition(vector<int>& nums,int low,int high){
        //choose the pivot
        
        int pivot=nums[high];
        //Index of smaller element and Indicate
        //the right position of pivot found so far
        int i=(low-1);
        
        for(int j=low;j<=high;j++)
        {
            //If current element is smaller than the pivot
            if(nums[j]<pivot)
            {
                //Increment index of smaller element
                i++;
                swap(nums[i],nums[j]);
                for(int i=0;i<nums.size();i++){
                    cout<<nums[i]<<',';
                }
                cout<<endl;
            }
        }
        swap(nums[i+1],nums[high]);
        return (i+1);
    }
    
    // The Quicksort function Implement
                
    void quick_sort(vector<int>& nums,int low,int high){
        // when low is less than high
        if(low<high)
        {
            // pi is the partition return index of pivot
            
            int pi=partition(nums,low,high);
            
            //Recursion Call
            //smaller element than pivot goes left and
            //higher element goes right
            quick_sort(nums,low,pi-1);
            quick_sort(nums,pi+1,high);
        }
    }

};


int main(){
    vector<int> nums = {5,4,3,2,1};//
    Solution a;
    a.bubble_sort(nums);
    // a.quick_sort(nums,0,nums.size()-1);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<',';
    }
    
    cout<<endl;
    cout<<"end"<<endl;
    return 0;
}