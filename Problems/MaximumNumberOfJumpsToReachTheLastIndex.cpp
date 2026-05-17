/*
 * @lc app=leetcode id=1999862718 lang=cpp
 *
 * MaximumNumberOfJumpsToReachTheLastIndex
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(n, -1);
        dp[n-1]=0;
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(dp[j]==-1)continue;
                if(abs(1LL*(nums[i]-nums[j]))<=target){
                    dp[i]=max(dp[i], 1+dp[j]);
                }
            }
        }
        return dp[0];
    }
};