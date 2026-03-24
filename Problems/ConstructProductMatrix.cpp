/*
 * @lc app=leetcode id=1958185915 lang=cpp
 *
 * ConstructProductMatrix
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    const int N = 12345;
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<ll>>pre(n, vector<ll>(m));
        vector<vector<ll>>suff(n, vector<ll>(m));
        vector<ll>prefix(n+1), suffix(n+1);
        for(int i=0;i<n;i++){
            pre[i][0] = grid[i][0]%N;
            for(int j=1;j<m;j++){
                pre[i][j] = (pre[i][j-1] * grid[i][j]%N)%N;
            }
            if(!i)prefix[i] = pre[i][m-1];
            else prefix[i] = (prefix[i-1] * pre[i][m-1])%N;
        }
        for(int i = n-1;i>=0;i--){
            suff[i][m-1]=grid[i][m-1]%N;
            for(int j = m-2;j>=0;j--){
                suff[i][j] = (suff[i][j+1] * grid[i][j]%N)%N;
            }
            if(i==n-1)suffix[i]=suff[i][0];
            else suffix[i] = (suffix[i+1] * suff[i][0])%N;
        }
        vector<vector<int>>ret(n, vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ll cnt = 1;
                if(i)cnt = (cnt * prefix[i-1])%N;
                if(i+1 < n)cnt = (cnt * suffix[i+1])%N;
                if(j) cnt = (cnt * pre[i][j-1])%N;
                if(j+1<m)cnt = (cnt * suff[i][j+1])%N;
                ret[i][j]=cnt;
            }
        }
        return ret;
    }
};