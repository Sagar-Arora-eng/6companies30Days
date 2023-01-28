// Given two integers n and k, return the kth lexicographically 
// smallest integer in the range [1, n].
#include<bits/stdc++.h>
using namespace std; 

int count(int n, int prefix){
    if(n < prefix) return 0; 
    if(n ==  prefix) return 1; 

    long minPre = prefix, maxPre = prefix; 
    int count = 1; 
    while(1){
        minPre = minPre*10; 
        maxPre = maxPre*10 + 9; 
        if(n < minPre) break; 
        if(minPre <= n && n <= maxPre){
            count += n-minPre+1; 
            break; 
        }
        count += maxPre-minPre+1;
    }
    return count; 
}

int findKthNumber(int n, int k, int prefix){
    for(int i=(prefix == 0 ? 1 : 0); i <= 9; i++){
        if(k == 0) return prefix; 
        int no_less_n = count(n, prefix*10 + i); 
        if(no_less_n >= k){
            return findKthNumber(n, k-1, prefix*10 + i); 
        }else{
            k -= no_less_n; 
        }
    }
    return prefix; 
}

int main(){
    int n, k; 
    cin>>n>>k; 
    findKthNumber(n, k, 0); 
    return 0; 
}