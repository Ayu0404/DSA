#include <bits/stdc++.h>
using namespace std;

// simple bubble sort
vector<int> bubble_sort(vector<int> nums, int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(nums[i]>nums[j]){
                swap(nums[i],nums[j]);
            }
        }
    }
    return nums;
}

int main() {
     vector<int> nums = { 1, 5, 3, 4, 2 };
    // simple bubble sort
     nums = bubble_sort(nums, nums.size());
    
     cout<<"Sorted Array\n";
     for(const auto& it:nums){
        cout<<it<<" ";
     }
     return 0;
}
