/*
 * @lc app=leetcode id=1990507702 lang=cpp
 *
 * MinimumImpossibleOr
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        map<int,int>mp;
        for(auto it:nums){
            mp[it]++;
        }
        for(int i=1;i<=(1LL<<32);i*=2){
            if(!mp.count(i)){
                return i;
            }
        }
        return -1;
    }
};