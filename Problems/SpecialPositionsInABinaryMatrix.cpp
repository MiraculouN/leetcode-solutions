/*
 * @lc app=leetcode id=1937202603 lang=cpp
 *
 * SpecialPositionsInABinaryMatrix
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>>row= mat, col=mat;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++)
                row[i][j] += row[i][j-1];
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++)
                col[i][j] += col[i-1][j];
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!mat[i][j])continue;
                if(col[n-1][j]==1 && row[i][m-1]==1)cnt++;
            }
        }
        return cnt;
    }
};