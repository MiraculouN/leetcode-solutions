/*
 * @lc app=leetcode id=1988568965 lang=cpp
 *
 * MaximizeTheDistanceBetweenPointsOnASquare
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<long long>v;
    int k;
    int side;
    int can(long long m){
        for(int st =0; st<v.size();st++){
            long long x = v[st];
            for(int i=0;i<k-1;i++){
                auto it= lower_bound(v.begin(), v.end(), x+m);
                if(it==v.end() ){
                    x = -1;
                    break;
                }
                x = *it;
            }
            if(x!=-1 && 4LL*side-abs(x-v[st])>=m)return 1;
        }
        return 0;
    }
    int maxDistance(int s, vector<vector<int>>& points, int kk) {
        k = kk;
        side = s;
        for(auto it:points){
            long long x = it[0], y = it[1];
            if(!x && y)v.push_back(y);
            else if(y==side && x)v.push_back(x+side);
            else if(x==side && y)v.push_back(1LL *side*3-y);
            else v.push_back(1LL *side*4-x);

        }
        sort(v.begin(), v.end());
        for(auto it:v)cout<<it<<' ';

        long long lo = 0, hi= 2*side, mid, ans=0;
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(can(mid) ){
                lo=mid+1;
            }
            else hi=mid-1;
        }
        return hi;
    }


};