/*
 * @lc app=leetcode id=1947052528 lang=cpp
 *
 * ClosestPrimeNumbersInRange
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    const int M = 1e6+5;

    vector<int>is_prime, primes;
    void sieve(){
        is_prime[1]=is_prime[0]=0;
        for(ll i=2;i<M;i++){
            if(is_prime[i]==1){
                primes.push_back(i);
                for(ll j=i*i;j<M;j+=i){
                    is_prime[j] = 0;
                }
            }
        }
    }

    vector<int> closestPrimes(int left, int right) {
        is_prime.assign(M,1);
        sieve();
        int num1 = -1, num2 = -1, diff=1e9;
        for(int i=1;i<primes.size();i++){
            int p1 = primes[i-1], p2=primes[i];
            if(p1 < left)continue;
            if(p2> right )continue;
            int d = p2 - p1;
            if(d < diff){
                diff= d;
                num1 = p1, num2 = p2;
            }
        }
        return {num1, num2};
        
    }
};