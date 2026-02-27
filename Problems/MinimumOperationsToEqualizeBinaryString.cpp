/*
 * @lc app=leetcode id=1933152129 lang=cpp
 *
 * MinimumOperationsToEqualizeBinaryString
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minOperations(string s, int k) {
        int zero=0;
        int n=s.length();
        for(auto it:s)zero += (it=='0');
        if(!zero)return 0;
        if(zero % k ==0)return zero/k;
        for(int ops=1;ops<=n;ops++){
            int tot = ops * k;
            if(tot < zero)continue;
            if((tot - zero) &1)continue;
            int mn = zero, one = n- zero;
            int mx = ops * one + (ops-1)* zero;
            if(ops &1){
                mx = ops * zero + (ops -1 )* one;
            }
            if(tot >=mn && tot<=mx )return ops;
        }
        return -1;
    }
};