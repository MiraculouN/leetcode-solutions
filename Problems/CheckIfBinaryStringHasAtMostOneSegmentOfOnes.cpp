/*
 * @lc app=leetcode id=1940198833 lang=cpp
 *
 * CheckIfBinaryStringHasAtMostOneSegmentOfOnes
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool checkOnesSegment(string s) {
        while(s.back()=='0'){
            s.pop_back();
        }
        for(auto it:s)if(it=='0')return 0;
        return 1;
    }
};