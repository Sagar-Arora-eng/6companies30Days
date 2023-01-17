#include<bits/stdc++.h>
using namespace std;

vector<int> smallestTrimmedNumbersV1(vector<string>& nums, vector<vector<int>>& queries) {
    int n = nums[0].size(); 
    int trimIdx, trimSize; 
    vector<int> ans; 
    for(auto q : queries){
        trimIdx = q[0]; 
        trimSize = q[1]; 
        vector<pair<string, int>> v; 
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i].substr(n-trimSize, trimSize), i}); 
        }
        sort(v.begin(), v.end()); 
        ans.push_back(v[trimIdx-1].second); 
    }
    for(int& x : ans) cout<<x<<" "; 
    return ans; 
}

vector<int> smallestTrimmedNumbersV2(vector<string>& nums, vector<vector<int>>& queries) {
    vector<int> ans; 
    int nums_len = nums.size(); 
    int n = nums[0].size(); 
    int query_len = queries.size(); 

    for(int i=0; i<query_len; i++){
        priority_queue<pair<string, int>> maxHeap;  
        for(int j=0; j<nums_len; j++){
        string s = nums[j].substr(n-queries[i][1], queries[i][1]); 
        maxHeap.push({s, j}); 
        if(maxHeap.size() > queries[i][0]) maxHeap.pop(); 
        }
    //   while(!maxHeap.empty()){
    //       cout<<maxHeap.top().first<<" "<<maxHeap.top().second<<endl;
    //       maxHeap.pop(); 
    //   }
        ans.push_back(maxHeap.top().second); 
    }
    return ans; 
}

int main(){
   
   int n1, n2; 
   cin>>n1>>n2; 
   vector<string> nums(n1); 
   vector<vector<int>> queries(n2, vector<int>(2)); 
   
   for(int i=0; i<n1; i++){
     cin>>nums[i]; 
   }
   for(int i=0; i<n2; i++){
     for(int j=0; j<2; j++){
        cin>>queries[i][j]; 
     }
   }

   
   
   vector<int> ans1 = smallestTrimmedNumbersV1(nums, queries); 
   for(int& x : ans1) cout << x << " "; 
   cout << endl;

   vector<int> ans2 = smallestTrimmedNumbersV2(nums, queries);  
   for(int& x : ans2) cout << x << " "; 
   cout << endl;

   return 0;
}