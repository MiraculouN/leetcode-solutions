/*
 * @lc app=leetcode id=1946525484 lang=cpp
 *
 * MinimumNumberOfSecondsToMakeMountainHeightZero
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& v) {
        ll lo = 1, hi= 1e16, mid, ans;

        auto can = [&](ll m)->bool{
            ll cnt = 0;
            for(auto it:v){
                ll lo = 0, hi=2e9, mid,ans;
                while(lo<=hi){
                    mid = lo+(hi-lo)/2;
                    ll time = mid*(mid+1)/2;
                    if(time > m){
                        hi=mid-1;
                        continue;
                    } 
                    if(time > m/it){
                        hi = mid-1;
                        continue;
                    }
                    time *= it;
                    if(time <=m){
                        lo=mid+1;
                        ans = mid;
                    }
                    else hi=mid-1;
                }

                ///stop at n where n*(n+1)/2*it <= m;
                ll x = ans;
                if(x >= h)return 1;
                cnt += x;
                if(cnt >=h)return 1;
            }
            return (cnt>=h);
        };
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(can(mid)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};