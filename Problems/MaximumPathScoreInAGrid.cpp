/*
 * @lc app=leetcode id=1991402913 lang=cpp
 *
 * MaximumPathScoreInAGrid
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int n, m, k;
    int no = 1e9;
    vector<vector<int>>v;
    int dp[202][202][404];
    int bst(int i, int j, int zero){
        if(i==n-1 && j==m-1){
            if(n+m-1-zero <= k)return v[n-1][m-1];
            return -1700;
        }
        if(dp[i][j][zero]!=no)return dp[i][j][zero];
        int ans = -1700;
        if(i+1<n) ans = max(ans, v[i][j] + bst(i+1, j,zero + (v[i+1][j]==0)));
        if(j+1<m) ans = max(ans, v[i][j] + bst(i, j+1,zero + (v[i][j+1]==0)));
        return dp[i][j][zero] = ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k_) {
        n = grid.size(), m=grid[0].size();
        v = grid;
        k = k_;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int h=0;h<m+n;h++)
                dp[i][j][h]=no;
            }
        }
        int ans = bst(0,0,v[0][0]==0);
        return (ans >= 0)? ans: -1;
    }
};