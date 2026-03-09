/*
 * @lc app=leetcode id=1942377798 lang=cpp
 *
 * FindAllPossibleStableBinaryArraysI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    int limit;
    int dp[205][205][2];
    const int N = 1e9+7;
    ll count(int zero, int one, int t){
        if(zero<0 || one <0)return 0;
        if(!zero && !one){
            return 1;
        }
        if(dp[zero][one][t]!=-1)return dp[zero][one][t];
        ll ans = 0;
        for(int i=1;i<=limit;i++){
            if(t)ans = (ans + count(zero-i, one, 0))%N;
            else ans = (ans + count(zero, one-i, 1))%N;
            
        }
        return dp[zero][one][t]=ans;

    }
    int numberOfStableArrays(int zero, int one, int l) {
        limit = l;
        memset(dp, -1 , sizeof(dp));
        return (count(zero, one ,0)+count(zero, one, 1))%N;
    }
};