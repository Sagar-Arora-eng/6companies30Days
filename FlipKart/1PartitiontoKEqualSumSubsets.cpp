#include<bits/stdc++.h>
using namespace std;

vector<bool> visited; 
bool helper(vector<int>& nums, int idx, int n, int k, int target, int curr_sum){
    if(idx == n) return false; 
    if(k == 1) return true; 
    if(curr_sum == target){
        return  helper(nums, 0, n, k-1, target, 0); 
    }
    for(int j=idx; j<n; j++){
        if(curr_sum + nums[j] <= target && !visited[j]){
            visited[j] = true; 
            if(helper(nums, j+1, n, k, target, curr_sum+nums[j])) return true;
            visited[j] = false; 
        }
    }
    return false;        
}

 bool canPartitionKSubsets(vector<int>& nums, int k) {
    int n = nums.size(); 
    if(k == 1) return true; 
    int sum = 0; 

    for(int x : nums) sum += x; 

    if(sum%k) return false; 
    sum /= k; 
    visited.assign(n, false); 
    return helper(nums, 0, n, k, sum, 0); 

}

int main(){
    int n;  
    cin>>n; 
    vector<int> nums(n); 
    for(int& x : nums) cin>>x; 
    int k; 
    cin>>k; 

    canPartitionKSubsets(nums, k) ? cout<<"True"<<endl : cout<<"False"<<endl; 

    return 0; 
}