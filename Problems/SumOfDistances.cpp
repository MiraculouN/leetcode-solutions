/*
 * @lc app=leetcode id=1988569907 lang=cpp
 *
 * SumOfDistances
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<ll>ret;
        map<int, vector<ll>>mp, pre;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto it:mp){
            int x = it.first;
            pre[x] = it.second;
            ll cnt=0;
            for(auto &itr: pre[x]){
                cnt += itr;
                itr = cnt;
            }
        }

        for(int i=0;i<n;i++){
            int x = nums[i];
            auto it = lower_bound(mp[x].begin(), mp[x].end(),i);
            int idx = it - mp[x].begin();
            int sz = mp[x].size();
            ll cntL = idx+1 , cntR= sz - cntL;
            ll sum = cntL * i - pre[x][idx] ;
            ll sum2 = pre[x][sz-1]-pre[x][idx];
            sum += (sum2 - (1LL*i*cntR));
            ret.push_back(sum);
        }
        return ret;
    }
};