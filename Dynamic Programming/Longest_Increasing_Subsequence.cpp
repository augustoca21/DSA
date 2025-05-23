#include <iostream>
#include <vector>
using namespace std;

int lengthOfLIS1(vector<int>& nums) {
    int n=nums.size();
    vector<int> dp (n,1);
    for (int i=n-1; i >=0; i--)
        for (int j=i+1; j<n;j++){ 
            if (nums[i]<nums[j])
                dp[i]=max(dp[i], dp[j]+1);
        }
    return *max_element(dp.begin(), dp.end());
            
}

int lengthOfLIS(vector<int>& arr) {
    int n=arr.size();
    vector<int> dp (n,1);
    int mags = 1;
    for (int i=0; i< n; i++) {
        for (int j=0; j<i; j++) {
            if (arr[i]>arr[j]) {
                dp[i]= max(dp[i],dp[j]+1);
                mags = max(mags, dp[i]);
            }
        }
    }
    return mags;
            
}

int main() {
    
    return 0;
}