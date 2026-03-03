/*
 * @lc app=leetcode id=1936180696 lang=cpp
 *
 * FindKthBitInNthBinaryString
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    char kth_char(int n, int k, int inv){
        int p = (n-1)/2;
        if(n==1){
            if(!inv)return '0';
            return '1';
        }
        if(k == p + 1){
           if(!inv) return '1';
           return '0';
        }
        if(k > p){
            k -= p+1;
            k = p - k +1;
            return kth_char(n/2, k, inv^1);
        }
        return kth_char(n/2 , k, inv);
    }
    char findKthBit(int n, int k) {
        int l = 1;
        for(int i=2;i<=n;i++){
            l = l* 2+1;
        }
        return kth_char(l, k, 0);
    }
};