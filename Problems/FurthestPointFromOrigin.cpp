/*
 * @lc app=leetcode id=1988569784 lang=cpp
 *
 * FurthestPointFromOrigin
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0 , cnt=0;
        for(auto it:moves){
            l += (it=='L');
            l -=(it=='R');
            cnt+= (it=='_');
        }
        return abs(l)+cnt;
    }
};