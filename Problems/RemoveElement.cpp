/*
 * @lc app=leetcode id=1995336504 lang=cpp
 *
 * RemoveElement
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n= nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                int ok = 0;
                for(int j=i+1;j<n;j++){
                    if(nums[j]!=val){
                        swap(nums[j], nums[i]);
                        ok =1;
                        break;
                    }
                }
                if(!ok)break;   
            }
        }
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]==val)break;
            else k++;
        }
        return k;
    }
};