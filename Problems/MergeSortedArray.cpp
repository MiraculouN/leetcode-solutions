/*
 * @lc app=leetcode id=1995335222 lang=cpp
 *
 * MergeSortedArray
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>nums;
        int i=0, j=0;
        while(i<m && j<n){
            if(nums1[i]< nums2[j]){
                nums.push_back(nums1[i]);
                i++;
            }
            else {
                nums.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            nums.push_back(nums1[i]);
            i++;
        }
        
        while(j<n){
            nums.push_back(nums2[j]);
            j++;
        }
        nums1 = nums;
    }
};