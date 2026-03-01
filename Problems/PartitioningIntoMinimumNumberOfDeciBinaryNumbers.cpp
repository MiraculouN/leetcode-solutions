/*
 * @lc app=leetcode id=1934158462 lang=cpp
 *
 * PartitioningIntoMinimumNumberOfDeciBinaryNumbers
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minPartitions(string n) {
        int mx=0;
        for(auto it: n){
            mx = max(mx , it-'0');
        }
        return mx;
    }
};