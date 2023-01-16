#include<bits/stdc++.h>
using namespace std;

string fractionToDecimal(int numerator, int denominator){
    if(numerator == 0) return "0"; 

    string ans; 
    if(numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0) ans += '-'; 
    numerator = abs(numerator); 
    denominator = abs(denominator); 

    long quotient = long(numerator)/denominator; 
    long rem = ((long)numerator)%denominator; 

    ans += to_string(quotient); 
    if(rem == 0) return ans; 

    ans += '.'; 

    unordered_map<long, int> appeared; 

    while(rem){
        if(appeared.find(rem) != appeared.end()){
            int pos = appeared[rem]; 
            ans.insert(pos, "("); 
            ans += ')'; 
            break; 
        }else{
            appeared[rem] = ans.size(); 
            rem *= 10; 
            quotient = rem/denominator; 
            rem = rem%denominator; 
            ans += to_string(quotient); 
        }
    }   
    return ans; 
}

int main(){
   int  numerator, denominator; 
   cin>>numerator>>denominator; 

   string ans = fractionToDecimal(numerator, denominator); 
   cout<<ans<<endl;

   return 0;
}