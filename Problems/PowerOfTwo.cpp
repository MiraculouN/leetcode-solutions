/*
 * @lc app=leetcode id=1990430313 lang=cpp
 *
 * PowerOfTwo
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 0)return 0;
        return (__builtin_popcount(n)==1);
    }
};