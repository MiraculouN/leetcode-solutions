/*
 * @lc app=leetcode id=1947063972 lang=cpp
 *
 * SplitArrayByPrimeIndices
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    const int M = 1e5+5;

    vector<int>is_prime;
    void sieve(){
        is_prime[1]=is_prime[0]=0;
        for(ll i=2;i<M;i++){
            if(is_prime[i]==1){
                ///primes.push_back(i);
                for(ll j=i*i;j<M;j+=i){
                    is_prime[j] = 0;
                }
            }
        }
    }

    long long splitArray(vector<int>& nums) {
        is_prime.assign(M, 1);
        sieve();
        ll sumA=0, sumB=0;
        for(int i=0;i<nums.size();i++){
            if(is_prime[i]){
                sumA += nums[i];
            }
            else sumB += nums[i];
        }
        return abs(sumA - sumB);
    }
};