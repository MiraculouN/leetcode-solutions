/*
 * @lc app=leetcode id=1988604974 lang=cpp
 *
 * DetectCyclesIn2dGrid
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int n, m;
    int valid(int x, int y){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    vector<vector<char>>v;
    vector<vector<int>>vis;
    int dx[4]={1, -1, 0, 0};
    int dy[4]={ 0, 0,1, -1};

    int dfs(int x, int y, int xp, int yp, int len){
        if(vis[x][y]){
            return len >=4;
        }
        vis[x][y]=1;
        int ans = 0;
        for(int i=0;i<4;i++){
            int x_= x+dx[i];
            int y_=y+dy[i];
            if(x_==xp && y_==yp)continue;
            if(valid(x_, y_) && v[x][y]==v[x_][y_])
                ans = ans | dfs(x_, y_, x, y, len+1);
        }
        return ans;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        v = grid;
        n = grid.size(), m=grid[0].size();
        vis.assign(n , vector<int>(m, 0));
        int ans =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j]){
                    ans = (ans | dfs(i, j, -1, -1, 1));
                }
            }
        }
        return ans;

    }
};