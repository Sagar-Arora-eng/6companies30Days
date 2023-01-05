#include<bits/stdc++.h>
using namespace std;

int findUnsortedSubarray(vector<int>& nums){
    int n = nums.size(); 
    int start = 0, end = n-1; 

    while(start < n-1 && nums[start] <= nums[start+1]) start++; 
    while(end > 0 && nums[end-1] <= nums[end]) end--;

    if(start == n-1) return 0;  

    int minVal = INT_MAX, maxVal = INT_MIN; 

    for(int i=start; i<= end; i++){
        minVal = min(minVal, nums[i]); 
        maxVal = max(maxVal, nums[i]); 
    }

    while(start > 0 && nums[start-1] > minVal) start--; 
    while(end < n-1 && nums[end+1] < maxVal) end++; 

    return end-start+1;
}

int main(){
   int n; 
   cin>>n; 

   vector<int> nums(n); 
   for(int& x : nums) cin>>x;

   cout << findUnsortedSubarray(nums) <<endl;

   return 0;
}