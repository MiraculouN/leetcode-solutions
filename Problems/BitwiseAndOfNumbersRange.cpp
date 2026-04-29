/*
 * @lc app=leetcode id=1990448950 lang=cpp
 *
 * BitwiseAndOfNumbersRange
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int AND=0;
        for(int i=0;i<32;i++){
            if((left & (1<<i)) && (right & (1<<i)) && right-left <= (1<<i))
                AND += (1<<i);
        }
        return AND;
    }
};