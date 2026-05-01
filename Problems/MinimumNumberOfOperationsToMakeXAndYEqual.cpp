/*
 * @lc app=leetcode id=1992618810 lang=cpp
 *
 * MinimumNumberOfOperationsToMakeXAndYEqual
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        int inf=1e9;
        vector<int>dist(1e5+5, inf);
        queue<int>q;
        q.push(x);
        dist[x]=0;
        while(!q.empty()){
            int node=q.front();q.pop();

            /// node/5
            if(node%5==0 && node/5>=0 && dist[node/5]==inf){
                q.push(node/5);
                dist[node/5]=1+dist[node];
            }

            
            /// node/11
            if(node%11==0 && node/11>=0 && dist[node/11]==inf){
                q.push(node/11);
                dist[node/11]=1+dist[node];
            }

            // node+1

            if(node+1 <=1e5 && dist[node+1]==inf){
                q.push(node+1);
                dist[node+1]=1+dist[node];
            }
            ///node-1
            if(node-1 >=0 && dist[node-1]==inf){
                q.push(node-1);
                dist[node-1]=1+dist[node];
            }

        }
        return dist[y];
    }
};