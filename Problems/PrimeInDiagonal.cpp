/*
 * @lc app=leetcode id=1947324540 lang=cpp
 *
 * PrimeInDiagonal
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long 

class Solution {
public:
    const int M=4e6;
    vector<int>is_prime;
    vector<int>primes;
    void sieve(){
        is_prime[1]=is_prime[0]=0;
        for(ll i=2;i<M;i++){
            if(is_prime[i]){

                primes.push_back(i);
                for (ll j = i * i; j < M; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        is_prime.assign(M, 1);
        sieve();
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int v1=nums[i][i];
            int v2=nums[i][n-1-i];
            if(is_prime[v1])ans=max(ans, v1);
            if(is_prime[v2])ans=max(ans, v2);
        }
        return ans;
        
    }
};