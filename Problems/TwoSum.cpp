/*
 * @lc app=leetcode id=1934796271 lang=cpp
 *
 * TwoSum
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        int i=0, j=nums.size()-1;
        while(i<j){
            int sum = v[i].first +v[j].first;
            if(sum == target){
                return {v[i].second, v[j].second};
            }
            else if(sum < target) i++;
            else j--;
        }
        return {};
    }
};