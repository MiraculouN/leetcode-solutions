/*
 * @lc app=leetcode id=1941325498 lang=cpp
 *
 * FindUniqueBinaryString
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string,int>mp;
        for(int i=0;i<n;i++)mp[nums[i]]++;
        for(int i=0;i<(1<<n);i++){
            string s;
            for(int k=0;k<n;k++){
                if(i & (1<<k))
                    s+='1';
                else s+='0';
            }
            if(!mp.count(s))
                return s;
        }
        return "0";
    }
};