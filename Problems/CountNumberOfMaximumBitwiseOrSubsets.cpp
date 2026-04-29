/*
 * @lc app=leetcode id=1990484305 lang=cpp
 *
 * CountNumberOfMaximumBitwiseOrSubsets
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int mx =0;
        for(auto it:nums)mx = (mx | it);
        int n= nums.size();
        int cnt=0;
        for(int mask=1;mask<(1<<n);mask++){
            int subset_or=0;
            for(int i=0;i<n;i++){
                if(mask & (1<<i)){
                    subset_or = (subset_or | nums[i]);
                }
            }
            if(subset_or == mx)cnt++;
        }
        return cnt;
    }
};