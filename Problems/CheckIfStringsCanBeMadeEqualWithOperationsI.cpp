/*
 * @lc app=leetcode id=1962753894 lang=cpp
 *
 * CheckIfStringsCanBeMadeEqualWithOperationsI
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string e1; e1 += s1[0]; e1+=s1[2];
        string e2; e2 += s2[0]; e2+=s2[2];
        string o1; o1 += s1[1]; o1+=s1[3];
        string o2; o2 += s2[1]; o2+=s2[3];
        sort(o1.begin(), o1.end());
        sort(o2.begin(), o2.end());
        sort(e1.begin(), e1.end());
        sort(e2.begin(), e2.end());
        return e1==e2 && o1==o2;


    }
};