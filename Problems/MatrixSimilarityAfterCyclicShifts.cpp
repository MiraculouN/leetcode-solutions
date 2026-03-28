/*
 * @lc app=leetcode id=1961194243 lang=cpp
 *
 * MatrixSimilarityAfterCyclicShifts
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        vector<vector<int>>org = mat;
        int n = mat.size(), m = mat[0].size();
        while(k--){
            for(int i=0;i<n;i++){
                deque<int>dq;
                for(int j=0;j<m;j++)dq.push_back(mat[i][j]);
                if(i%2==0){
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
                else{
                    dq.push_front(dq.back());
                    dq.pop_back();
                }
                for(int j=0;j<m;j++)mat[i][j]= dq[j];
            }
        }
        return mat==org;
    }
};