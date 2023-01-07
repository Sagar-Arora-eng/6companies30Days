#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int>& nums, vector<int>& numsDivide){

    sort(nums.begin(), nums.end()); 
    sort(numsDivide.begin(), numsDivide.end()); 

    int count = 0; 
    int gcd_numsD = numsDivide[0]; 

    for(int i=1; i<numsDivide.size(); i++){
        gcd_numsD = __gcd(gcd_numsD, numsDivide[i]); 
    }

    if(nums[0] > gcd_numsD) return -1; 

    for(int i=0; i<nums.size(); i++){
        if(gcd_numsD%nums[i] == 0) return count; 
        count++; 
    }

    return -1; 
}

int main(){
   int n1, n2; 
   cin>>n1>>n2; 

   vector<int> nums(n1), numsDivide(n2); 

   for(int &x : nums) cin>>x; 
   for(int &x : numsDivide) cin>>x; 

   cout << minOperations(nums, numsDivide) << endl;

   return 0;
}