/*
 * @lc app=leetcode id=1993402340 lang=cpp
 *
 * PathWithMaximumProbability
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>dist(n+1, 0);
        vector<vector<pair<int,double>>>v(n+1);
        for(int i=0;i<edges.size();i++){
            int a=edges[i][0], b=edges[i][1];
            double prop= succProb[i];
            v[a].push_back({b, prop});
            v[b].push_back({a, prop});
        }

        priority_queue<pair<double, int>>pq ; ///{prop, node};
        pq.push({1, start_node});
        dist[start_node]=1;

        while(!pq.empty()){
            int node= pq.top().second;
            double  prop = pq.top().first;
            pq.pop();

            if(dist[node] > prop)continue;
            for(auto it:v[node]){
                int a=it.first;
                double p= it.second;
                if(dist[a] < p*prop ){
                    dist[a]=p*prop;
                    pq.push({dist[a], a});
                }
            }
        }
        return dist[end_node];

    }
};