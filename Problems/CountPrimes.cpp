/*
 * @lc app=leetcode id=1947326502 lang=cpp
 *
 * CountPrimes
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long

class Solution {
public:

    const int M=5e6;
    vector<int>is_prime;
    vector<int>primes;
    int sieve(int n){
        is_prime[1]=is_prime[0]=0;

        int cnt=1;// no of primes<n
        for(ll i=3;i<n;i+=2){

            if(is_prime[i]){
                cnt++;
                ///primes.push_back(i);
                for (ll j = i * i; j < n; j += i) {
                    is_prime[j] = 0;
                }
            }
        }
        return cnt;
    }
    int countPrimes(int n) {
        if(n<=2)return 0;
        is_prime.assign(n, 1);
        return sieve(n);

    }
};