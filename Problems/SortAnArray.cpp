/*
 * @lc app=leetcode id=1961776323 lang=cpp
 *
 * SortAnArray
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    void Merge(vector<int>&v , int l, int r){
        vector<int>v1, v2;
        /// v1 => v[l]...v[mid]
        /// v2 => v[mid+1]...v[r]
        int mid = (l+r)/2;
        for(int i=l;i<=mid;i++)v1.push_back(v[i]);
        for(int i=mid+1;i<=r;i++)v2.push_back(v[i]);
        int i1 = 0, i2=0;
        vector<int>sorted_v;
        while(i1 < v1.size() && i2 < v2.size()){
            if(v1[i1] < v2[i2]){
                sorted_v.push_back(v1[i1]);
                i1++;
            }
            else{
                sorted_v.push_back(v2[i2]);
                i2++;
            }
        }
        /// if i1 reached v1.size() but i2 didn't reach v2.size();
        while(i2 < v2.size()){
            sorted_v.push_back(v2[i2]);
            i2++;
        }
        /// if i2 reached v2.size() but i1 didn't reach v1.size();
        while(i1 < v1.size()){
            sorted_v.push_back(v1[i1]);
            i1++;
        }
        for(int i=0, j=l;j<=r;j++, i++){
            v[j] = sorted_v[i];
        }

    }

    void MergeSort(vector<int>&v, int l,int r){
        if(l==r)return ;
        int mid = (l+r)/2;
        MergeSort(v, l, mid);
        MergeSort(v, mid+1, r);
        ///// then the subarray from l to mid is sorted
        ///// then the subarray from  mid+1 to r is sorted
        /// then combine v[l]...v[mid] and v[mid+1]..v[r];
        Merge(v, l, r);

    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        MergeSort(nums, 0, n-1);
        return nums;
        
    }
};