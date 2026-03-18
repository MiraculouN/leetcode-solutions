/*
 * @lc app=leetcode id=1952454467 lang=cpp
 *
 * CountSubmatricesWithTopLeftElementAndSumLessThanK
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>v=grid;
        auto sum = [&](int x1, int y1, int x2, int y2){
            int ans = v[x2][y2] ;
            if(y1) ans -=v[x2][y1-1];
            if(x1) ans -= v[x1-1][y2];
            if(y1 && x1) ans += v[x1-1][y1-1];
            return ans;
        };
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                v[i][j] += v[i][j-1];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                v[i][j] += v[i-1][j];
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sum(0,0,i,j) <= k)cnt++;
            }
        }
        return cnt;
        
    }
};