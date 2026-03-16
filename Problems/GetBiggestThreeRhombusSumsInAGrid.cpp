/*
 * @lc app=leetcode id=1949581187 lang=cpp
 *
 * GetBiggestThreeRhombusSumsInAGrid
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>v;
        int n= grid.size(), m=grid[0].size();
        auto valid = [&](int x,int y){
            return (x>=0 && x<n && y>=0 && y<m);
        };
        auto sum = [&](int x, int y, int x1 , int y1 , int dx,int dy){
            int cnt=0;
            while(x!=x1){
                x += dx;
                y += dy;
                cnt += grid[x][y];
            }
            return cnt;
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v.push_back(grid[i][j]);
                for(int l=1;l<=min(n, m);l++){
                    int x = i, y = j;
                    if(!valid(x+l, y+l))continue;
                    if(!valid(x-l, y+l))continue;
                    if(!valid(x, y+l*2))continue;
                    int cnt = sum(x, y, x-l, y+l, -1, 1);
                    cnt += sum(x-l, y+l, x, y+2*l, 1, 1);
                    cnt += sum(x, y+2*l,x+l, y+l, 1, -1 );
                    cnt += sum(x+l, y+l, x, y, -1, -1);
                    v.push_back(cnt);
                }
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        vector<int>ret ;
        for(int i=0;i<v.size();i++){
            if(ret.empty()==0 && ret.back()==v[i])continue;
            else ret.push_back(v[i]);
        }
        while(ret.size()>3)ret.pop_back();
        return ret;
    }
};