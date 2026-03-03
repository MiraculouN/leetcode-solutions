/*
 * @lc app=leetcode id=1936042152 lang=cpp
 *
 * MinimumSwapsToArrangeABinaryGrid
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n=grid.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            int idx = -1;
            for(int j=i;j<n;j++){
                int ok = 1;
                for(int k = n-1 ;k>=i+1;k--){
                    if(grid[j][k]!=0){
                        ok=0;
                        break;
                    }
                }
                if(ok){
                    idx = j;
                    break;
                }
            }
            if(idx==-1)return -1;
            while(idx !=i){
                cnt++;
                swap(grid[idx], grid[idx-1]);
                idx--;
            }
        }   
        return cnt;
    }
};