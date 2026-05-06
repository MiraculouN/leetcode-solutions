/*
 * @lc app=leetcode id=1995337075 lang=cpp
 *
 * RemoveElement
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        int idx = n-1;
        for(int i=0;i<n;i++){
            if(idx==i)break;
            if(nums[i]==val){
                swap(nums[i], nums[idx]);
                idx--;
                i--;
            }
        }
        int k=0;for(int i=0;i<n;i++){
            if(nums[i]==val)break;
            else k++;
        }
        return k;
    }
};