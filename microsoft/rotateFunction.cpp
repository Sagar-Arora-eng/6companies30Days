#include<bits/stdc++.h>
using namespace std;

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size(); 
    
    int ans = 0, intermediete = 0; 
    
    int total_sum = 0; 
    for(int i=0; i<n; i++){
        total_sum += nums[i];
        intermediete += i*nums[i]; 
    } 
    // cout<<"total_sum "<<total_sum<<endl;

    ans = intermediete; 
    // cout<<"intermediete "<<intermediete<<endl;
    // cout<<"ans "<<ans<<endl;
    for(int i=1; i<n; i++){
        intermediete = intermediete- n*nums[n-i] + total_sum; 
        ans = max(ans, intermediete);
        // cout<<"intermediete "<<intermediete<<endl;
        // cout<<"ans "<<ans<<endl;
    }

    return ans; 
}

int main(){
   int n; 
   cin>>n; 
   vector<int> nums(n); 
   for(int& x : nums) cin>>x;

   cout<<maxRotateFunction(nums)<<endl;  

   return 0;
}