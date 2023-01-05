#include<bits/stdc++.h>
using namespace std;

string prefix_function(string& s){
    int n = s.size(); 

    vector<int> pre_suff(n, 0); 

    for(int i=1; i<n; i++){
        int j = pre_suff[i-1]; 

        while(j > 0 && s[i] != s[j]) j = pre_suff[j-1]; 

        if(s[i] == s[j]) j++; 
        pre_suff[i] = j;
    }

    return s.substr(0, pre_suff[n-1]); 
}

int main(){
   string s; 
   cin>> s; 

   cout << prefix_function(s) << endl;

   return 0;
}