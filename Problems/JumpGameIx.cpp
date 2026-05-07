/*
 * @lc app=leetcode id=1997686445 lang=cpp
 *
 * JumpGameIx
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        stack<int>stk;
        vector<int>ret=nums, pre(n), suff(n);
        pre[0]=nums[0], suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1], nums[i]);
        }
        for(int i=n-2;i>=0;i--)suff[i]=min(suff[i+1], nums[i]);
        ret[n-1]=pre[n-1];
        for(int i=n-2;i>=0;i--){
            ret[i]=pre[i];
            if(i+1<n && pre[i] > suff[i+1])ret[i]=ret[i+1];
        }
        return ret;
    }
};