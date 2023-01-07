#include<bits/stdc++.h>
using namespace std;

int numberOfSubstrings(string& s){
    int n = s.size(); 

    int count = 0; 
    int idx_a = -1, idx_b = -1, idx_c = -1; 

    for(int i=0; i<n; i++){
        if(s[i] == 'a') idx_a = i; 
        if(s[i] == 'b') idx_b = i; 
        if(s[i] == 'c') idx_c = i; 

        count += min({idx_a, idx_b, idx_c}) + 1; 
    }
    return count; 
}

int main(){
   string s; 
   cin>>s; 

   cout << numberOfSubstrings(s) << endl;

   return 0;
}