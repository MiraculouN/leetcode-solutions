/*
 * @lc app=leetcode id=1952587996 lang=cpp
 *
 * CountSubmatricesWithEqualFrequencyOfXAndY
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>>vx(n, vector<int>(m,0));
        vector<vector<int>>vy(n, vector<int>(m,0));
        auto sum = [&](int x1, int y1, int x2, int y2, vector<vector<int>>&v){
            int ans = v[x2][y2] ;
            if(y1) ans -=v[x2][y1-1];
            if(x1) ans -= v[x1-1][y2];
            if(y1 && x1) ans += v[x1-1][y1-1];
            return ans;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='X')vx[i][j]=1;
                if(grid[i][j]=='Y')vy[i][j]=1;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                vx[i][j] += vx[i][j-1];
                vy[i][j] += vy[i][j-1];

            }
        }
        for(int j=0;j<m;j++){
            for(int i=1;i<n;i++){
                vx[i][j] += vx[i-1][j];
                vy[i][j] += vy[i-1][j];

            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(sum(0,0,i,j, vx)==sum(0,0,i,j,vy) && sum(0,0,i,j,vx)>0)cnt++;
            }
        }
        return cnt;


    }
};