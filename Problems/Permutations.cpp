/*
 * @lc app=leetcode id=1939823909 lang=cpp
 *
 * Permutations
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>ret;
        sort(nums.begin(), nums.end());

        do{
            ret.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));
        return ret;
        
    }
};