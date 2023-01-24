#include<bits/stdc++.h>
using namespace std;

long long maxMatrixSum(vector<vector<int>>& matrix) {
    int n = matrix.size(); 
    
    int total_neg = 0; 
    int max_neg = INT_MIN; 
    int least_pos = INT_MAX; 

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(matrix[i][j] < 0){
                total_neg++; 
                max_neg = max(max_neg, matrix[i][j]); 
            }else{
                least_pos = min(least_pos, matrix[i][j]); 
            }
        }
    }
    long long ans = 0 ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans += abs(matrix[i][j]); 
        }
    }
    if(total_neg%2 == 0) return ans; 
    
    if(abs(max_neg) > least_pos){
        ans -= (long long)2*least_pos; 
    }else{
        ans -= (long long)2*abs(max_neg); 
    }
    return ans; 
}

int main(){
   int n; 
   cin>>n; 
   vector<vector<int>> matrix(n, vector<int>(n)); 
   for(int i=0; i<n; i++){
     for(int j=0; j<n; j++){
        cin>>matrix[i][j]; 
     }
   }

   cout << maxMatrixSum(matrix) << endl;

   return 0;
}