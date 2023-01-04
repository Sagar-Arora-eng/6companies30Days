#include<bits/stdc++.h>
using namespace std;

string getHint(string secret, string guess) {
    int n = secret.size(); 
    vector<int> helper(n, -1); 
    
    int bull = 0, cow = 0; 
    for(int i=0; i<n; i++){
        if(secret[i] == guess[i]){
            bull++; 
            //cout<<"bull -> "<<i <<"-"<<i<<endl;
            helper[i] = 1; 
        }
    }     

    for(int i=0; i<n; i++){
        if(helper[i] == 1) continue; 
        for(int j=0; j<n; j++){
            if(secret[i] == guess[j] && helper[j] == -1){
                cow++; 
                //cout<<"cow -> "<<i <<"-"<<j<<endl;
                helper[j] = 2; 
                break;
            }
        }
    }
    string ans = to_string(bull) + "A" + to_string(cow) + "B"; 

    return ans;  
}

string getHintV2(string secret, string guess){
    int n = secret.size(); 
    unordered_map<char, int> s_map , g_map; 
    int bull = 0, cow = 0; 

    for(int i=0; i<n; i++){
        if(secret[i] == guess[i]) bull++; 
        else{
            char s = secret[i]; 
            char g = guess[i]; 

            g_map[s] > 0 ? cow++, g_map[s]-- : s_map[s]++; 
            s_map[g] > 0 ? cow++, s_map[g]-- : g_map[g]++; 
        }
    }
    string ans = to_string(bull) + "A" + to_string(cow) + "B"; 
    return ans; 
}

int main(){
   string secret, guess; 
   cin>>secret>>guess; 

//    cout << getHint(secret, guess) << endl; 
   cout << getHintV2(secret, guess) << endl;
   return 0;
}