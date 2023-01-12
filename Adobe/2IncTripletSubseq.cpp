#include<bits/stdc++.h>
using namespace std;

bool increasingTriplet(vector<int>& nums){
    int n = nums.size(); 
    vector<int>left_min(n), right_max(n); 

    left_min[0] = nums[0]; 
    right_max[n-1] = nums[n-1]; 

    for(int i=1; i<n; i++){
        left_min[i] = min(left_min[i-1], nums[i]); 
        right_max[n-i-1] = max(right_max[n-i], nums[n-i-1]); 
    }
    for(int i=0; i<n; i++){
        if(nums[i] > left_min[i] && nums[i] < right_max[i]) return true; 
    }
    return false; 
}

bool increasingTripletV2(vector<int>& nums){
    int n = nums.size(); 
    int first = INT_MAX,second = INT_MAX;

    for(int&x : nums){
        if(x <= first) first = x; 
        else if(x <= second) second = x;
        else return true; 
    }
    return true; 
}

int main(){
   int n; 
   cin>>n; 
   vector<int> nums(n); 
   for(int& x: nums) cin>>x; 

   increasingTriplet(nums) ? cout<<"true"<<endl : cout<<"false"<<endl;
   increasingTripletV2(nums) ? cout<<"true"<<endl : cout<<"false"<<endl;

   return 0;
}