/*
 * @lc app=leetcode id=1989373976 lang=cpp
 *
 * CheckIfThereIsAValidPathInAGrid
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int n, m;
    vector<vector<int>>v, vis;
    int valid(int x, int y){
        return (x>=0 && y>=0 && x<n && y<m);
    }
    int dfs(int x, int y){
        if(x==n-1 && y==m-1)return 1;
        vis[x][y]=1;
        int ans = 0;
        if(v[x][y]==1){
            if(valid(x, y+1) && !vis[x][y+1]&& (v[x][y+1]==3 || v[x][y+1]==5 || v[x][y+1]==1))
                ans = dfs(x, y+1);
            if(valid(x, y-1) && !vis[x][y-1]&& (v[x][y-1]==4 || v[x][y-1]==6 || v[x][y-1]==1))
                ans = dfs(x, y-1);
        }
        else if(v[x][y]==2){
            if(valid(x+1, y) && !vis[x+1][y]&& (v[x+1][y]==6 || v[x+1][y]==5 || v[x+1][y]==2))
                ans = ans  | dfs(x+1, y);
            
            if(valid(x-1, y) && !vis[x-1][y]&& (v[x-1][y]==4 || v[x-1][y]==3 || v[x-1][y]==2))
                ans = ans  | dfs(x-1, y);
        }
        else if(v[x][y]==4 || v[x][y]==3){
            if(valid(x+1, y) && !vis[x+1][y] && (v[x+1][y]==5 || v[x+1][y]==6 || v[x+1][y]==2))
                ans = (ans | dfs(x+1, y));
            if(v[x][y]==3 && 
            valid(x, y-1) && !vis[x][y-1] && (v[x][y-1]==4 || v[x][y-1]==1 || v[x][y-1]==6))
                ans = (ans | dfs(x, y-1));
            if(v[x][y]==4 && 
            valid(x, y+1) && !vis[x][y+1] && (v[x][y+1]==3 || v[x][y+1]==1 || v[x][y+1]==5))
                ans = (ans | dfs(x, y+1));
        }
        else if(v[x][y]==5){
            if(valid(x, y-1) &&!vis[x][y-1]&& (v[x][y-1]==6 || v[x][y-1]==4 || v[x][y-1]==1)){
                ans = ans | dfs(x, y-1);
            }
            if(valid(x-1, y) &&!vis[x-1][y]&& (v[x-1][y]==3 || v[x-1][y]==4 || v[x-1][y]==2)){
                ans = ans | dfs(x-1, y);
            }
        }
        else{
            if(valid(x, y+1) && !vis[x][y+1] &&(v[x][y+1]==5 || v[x][y+1]==3 || v[x][y+1]==1)){
                ans = ans | dfs(x, y+1);
            }
            
            if(valid(x-1, y) && !vis[x-1][y] &&(v[x-1][y]==2 || v[x-1][y]==3 || v[x-1][y]==4)){
                ans = ans | dfs(x-1, y);
            }
        }
        return ans;

    }
    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size(), m=grid[0].size();
        vis.assign(n+1, vector<int>(m+1, 0));
        v = grid;
        return dfs(0,0);

    }
};