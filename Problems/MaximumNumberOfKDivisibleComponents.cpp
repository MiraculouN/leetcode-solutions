/*
 * @lc app=leetcode id=1988569614 lang=cpp
 *
 * MaximumNumberOfKDivisibleComponents
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    vector<vector<int>>v;
    vector<int>val;
    int cuts=0;
    int k;
    ll dfs(int node, int p){
        ll sum =val[node]%k;
        for(auto it:v[node]){
            if(it==p)continue;
            ll sum_it = dfs(it, node);
            if(sum_it %k==0){
                cuts++;
            }
            sum = (sum + sum_it)%k;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k_) {
        v.assign(n , {});
        val = values;
        k = k_;
        for(auto it:edges){
            int a = it[0], b = it[1];
            v[a].push_back(b);
            v[b].push_back(a);
        }
        dfs(0, -1);
        return cuts+1;
    }
};