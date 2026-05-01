/*
 * @lc app=leetcode id=1992622768 lang=cpp
 *
 * JumpGameIii
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n= arr.size();
        int inf = 1e9;
        vector<int>lvl(n,inf);
        queue<int>q;
        q.push(start);
        lvl[start]=0;
        while(!q.empty()){
            int node = q.front();q.pop();
            //// node + arr[node]
            if(node + arr[node]< n && lvl[node + arr[node]]==inf){
                lvl[node + arr[node]]=1+lvl[node];
                q.push(node + arr[node]);
            }
            //node - arr[node]
            
            if(node - arr[node]>=0 && lvl[node - arr[node]]==inf){
                lvl[node - arr[node]]=1+lvl[node];
                q.push(node - arr[node]);
            }
        }
        for(int i=0;i<n;i++){
            if(arr[i]==0 && lvl[i]!=inf)return 1;
        }
        return 0;
    }
};