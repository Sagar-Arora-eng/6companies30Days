#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;

void combinationSum3Helper(int k, int n, int val, vector<int> helper){
    
    if(val > 9){
        if(k == 0 && n == 0) ans.push_back(helper); 
        return; 
    }
    if(k == 0 && n == 0){
        ans.push_back(helper); 
        return; 
    }
    if((k != 0 && n == 0) || (k == 0 && n != 0)){
        return; 
    }

    helper.push_back(val); 
    combinationSum3Helper(k-1, n-val, val+1, helper);
    helper.pop_back(); 
    combinationSum3Helper(k, n, val+1, helper); 

    return;  
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> helper; 
    combinationSum3Helper(k, n, 1, helper); 
    return ans; 
}

int main(){
   int k, n; 
   cin>>k>>n; 

   vector<vector<int>> res = combinationSum3(k, n); 

   return 0;
}