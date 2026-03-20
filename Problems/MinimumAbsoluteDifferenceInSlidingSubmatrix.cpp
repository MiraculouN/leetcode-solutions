/*
 * @lc app=leetcode id=1954186656 lang=cpp
 *
 * MinimumAbsoluteDifferenceInSlidingSubmatrix
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>>ret;
        for(int i=0;i<n;i++){
            vector<int>v;
            for(int j=0;j<m;j++){
                if(i+k-1 >= n || j+k-1 >=m)continue;
                vector<int>vals;
                for(int i1 = i ;i1 < i+k;i1++){
                    for(int j1=j ;j1< j+k;j1++){
                        vals.push_back(grid[i1][j1]);
                    }
                }
                sort(vals.begin() , vals.end());
                int mn = 1e9, ok=0;
                for(int i1=1;i1<vals.size();i1++){
                    if(vals[i1]!=vals[i1-1]){
                        mn = min(mn, vals[i1]-vals[i1-1]);
                        ok=1;
                    }
                }
                if(!ok)mn=0;
                v.push_back(mn);
            }
            if(!v.empty())
                ret.push_back(v);
        }
        return ret;

    }
};