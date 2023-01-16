#include<bits/stdc++.h>
using namespace std;

double knightProbabilityBottomUp(int n, int k, int row, int column, vector<vector<vector<double>>>& dp){
    if(row < 0 || column < 0 || row >= n || column >= n) return 0; 
    if(k == 0) return 1;
    if(dp[row][column][k] != 0) return dp[row][column][k]; 

    double sum = knightProbabilityBottomUp(n, k-1, row-2, column+1, dp)+
                knightProbabilityBottomUp(n, k-1, row-1, column+2, dp)+
                knightProbabilityBottomUp(n, k-1, row+1, column+2, dp)+
                knightProbabilityBottomUp(n, k-1, row+2, column+1, dp)+
                knightProbabilityBottomUp(n, k-1, row+2, column-1, dp)+
                knightProbabilityBottomUp(n, k-1, row+1, column-2, dp)+
                knightProbabilityBottomUp(n, k-1, row-1, column-2, dp)+
                knightProbabilityBottomUp(n, k-1, row-2, column-1, dp); 

    sum /= 8; 

    return dp[row][column][k] = sum; 
        
}

double knightProbability(int n, int k, int row, int column) {
    vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k+1, 0))); 

    return knightProbabilityBottomUp(n, k, row, column, dp); 
}

int main(){
   int n, k, row, column; 
   cin>>n>>k>>row>>column; 

   cout << knightProbability(n, k, row, column) << endl;

   return 0;
}