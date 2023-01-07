#include<bits/stdc++.h>
using namespace std;

long long cnt; 

void merge(vector<int>& helper, int start, int mid, int end, int& diff){

    int l = start, r = mid+1; 

    while(l <= mid && r <= end){
        if(helper[l] <= helper[r]+diff){
            cnt += end-r+1; 
            l++; 
        }else{
            r++; 
        }
    }

    sort(helper.begin()+start, helper.begin()+end+1); 

    return; 
}

void mergeSort(vector<int>& helper, int start, int end, int& diff){

    if(start == end) return;

    int mid = start+(end-start)/2; 

    mergeSort(helper, start, mid, diff); 
    mergeSort(helper, mid+1, end, diff); 

    merge(helper, start, mid, end, diff); 

    return; 
}

long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int& diff){
    cnt = 0; 
    int n = nums1.size(); 
    vector<int> helper(n); 

    // nums1[i]-nums1[j] <= nums2[i]-nums2[j]+diff where i < j
    // nums1[i]-nums2[i] <= nums1[j]-nums2[j]+diff

    for(int i=0; i<n; i++){
        helper[i] = nums1[i]-nums2[i]; 
    }

    mergeSort(helper, 0, n-1, diff); 

    return cnt; 
}

int main(){
   int n; 
   cin>>n; 
   vector<int> nums1(n), nums2(n); 
   
   for(int& x : nums1) cin>>x;
   for(int& x : nums2) cin>>x; 

   int diff; 
   cin>>diff; 

    
   cout << numberOfPairs(nums1, nums2, diff) << endl;

   return 0;
}