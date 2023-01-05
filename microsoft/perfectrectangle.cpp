#include<bits/stdc++.h>
using namespace std;

bool isRectangleCover(vector<vector<int>>& rectangles){
    int n = rectangles.size(); 

    if(n == 1) return true; 

    map<pair<int, int>, int> mpp; 

    for(auto v : rectangles){
        mpp[make_pair(v[0], v[1])]++; 
        mpp[make_pair(v[2], v[3])]++; 
        mpp[make_pair(v[0], v[3])]--; 
        mpp[make_pair(v[2], v[1])]--; 
    }

    int extremePts = 0; 

    for(auto it = mpp.begin(), end = mpp.end(); it != end; it++){
        if(abs(it->second) > 1) return false; 
        if(it->second != 0) extremePts++;  
    }

    return extremePts == 4 ? true : false; 
}

int main(){
   int n; 
   cin>>n; // number of rectangles

   vector<vector<int>> rectangles(n, vector<int>(4));
   for(int i=0; i<n; i++){
     for(int j=0; j<4; j++) cin>>rectangles[i][j]; 
   }

//    for(int i=0; i<n; i++){
//      for(int j=0; j<4; j++) cout<<rectangles[i][j]<<" "; 
//      cout<<endl;
//    }

   isRectangleCover(rectangles) ? cout << "true" << endl : cout<<"false"<<endl;

   return 0;
}