/*
 * @lc app=leetcode id=1990520786 lang=cpp
 *
 * FindIfArrayCanBeSorted
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n= nums.size();
        for(int itr = 1;itr<=n;itr++){
            for(int i=1;i<n;i++){
                if(nums[i-1] > nums[i] && (__builtin_popcount(nums[i-1])==__builtin_popcount(nums[i])))
                    swap(nums[i], nums[i-1]);
            }
        }
        return is_sorted(nums.begin(), nums.end());
        
    }
};