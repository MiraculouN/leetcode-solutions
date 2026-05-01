/*
 * @lc app=leetcode id=1992796866 lang=cpp
 *
 * RotateFunction
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int ans =0, sum=0;
        int n = nums.size();
        for(auto it:nums)sum+=it;
        for(int i=0;i<n;i++){
            ans = ans + i*nums[i];
        }
        int ret = ans;
        for(int i=n-1;i>=0;i--){
            ans = ans - (n-1)*nums[i] + sum-nums[i];
            ret = max(ans, ret);
        }
        return ret;
    }
};