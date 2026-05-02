/*
 * @lc app=leetcode id=1993400377 lang=cpp
 *
 * NetworkDelayTime
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>v;
        v.assign(n+1, {});
        int inf=1e9;
        vector<int>dist(n+1, 1e9);
        for(auto it:times){
            int a=it[0], b=it[1], w=it[2];
            v[a].push_back({b, w});
        }

        dist[k]=0;
        priority_queue<pair<int,int>>pq;
        pq.push({0, k});
        while(!pq.empty()){
            int node=pq.top().second;
            int cost = - pq.top().first;
            pq.pop();

            if(dist[node] < cost) continue;
            for(auto it:v[node]){
                int a=it.first;
                int w=it.second;
                if(dist[a] > w+cost){
                    dist[a]=w+cost;
                    pq.push({-dist[a], a});
                }
            }

        }

        int ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans, dist[i]);
        }
        if(ans == inf) ans=-1;
        return ans;


    }
};