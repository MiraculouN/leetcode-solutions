/*
 * @lc app=leetcode id=1955152642 lang=cpp
 *
 * FlipSquareSubmatrixVertically
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        vector<vector<int>>v;
        for(int i = x;i< x+k; i++){
            vector<int>vec;
            for(int j = y; j<y+k; j++){
                vec.push_back(grid[i][j]);
            }
            v.push_back(vec);
        }
        int p1 = 0, p2 = v.size()-1;
        while(p1<p2){
            swap(v[p1], v[p2]);
            p1++, p2--;
        }
         for(int i = x;i< x+k; i++){
            vector<int>vec;
            for(int j = y; j<y+k; j++){
                grid[i][j] = v[i - x][j - y];
            }
        }
        return grid;

    }
};