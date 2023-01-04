#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens) {

    int n = tokens.size(); 

    stack<string> stk; 
    for(int i=0; i<n; i++){
        if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
            int operand2 = stoi(stk.top()); stk.pop(); 
            int operand1 = stoi(stk.top()); stk.pop(); 
            int res; 
            if(tokens[i] == "+") res =  operand1 + operand2; 
            if(tokens[i] == "-") res =  operand1 - operand2;
            if(tokens[i] == "*") res =  operand1 * operand2;
            if(tokens[i] == "/") res =  operand1 / operand2;
            stk.push(to_string(res)); 
        }else{
            stk.push(tokens[i]); 
        }
    }
    int ans = stoi(stk.top()); 
    stk.pop(); 

    return ans; 
}

int main(){
   int n; 
   cin>>n; 

   vector<string> tokens(n);
   for(int i=0; i<n; i++) cin>>tokens[i]; 

   cout << evalRPN(tokens) << endl;

   return 0;
}