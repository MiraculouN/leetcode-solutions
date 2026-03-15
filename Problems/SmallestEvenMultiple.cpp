/*
 * @lc app=leetcode id=1947055106 lang=cpp
 *
 * SmallestEvenMultiple
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int smallestEvenMultiple(int n) {
        if(n % 2 ==1) n*=2;
        return n;
    }
};