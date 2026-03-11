/*
 * @lc app=leetcode id=1944443264 lang=cpp
 *
 * ComplementOfBase10Integer
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n)return 1;
        int xx = 0;
        for(int i=30;i>=0;i--){
            if(n & (1LL<<i)){
                xx = 1;
            }
            if(xx) n ^=(1LL<<i);
        }
        return n;
    }
};