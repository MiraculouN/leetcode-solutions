/*
 * @lc app=leetcode id=1992596468 lang=cpp
 *
 * KeysAndRooms
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int inf = 1e9;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>lvl(n, inf);
        queue<int>q;
        q.push(0);
        lvl[0]=0;
        while(q.empty()==0){
            int node = q.front();
            q.pop();
            for(auto it:rooms[node]){
                if(lvl[it]==inf){
                    q.push(it);
                    lvl[it]=1+lvl[node];
                }
            }
        }
        for(int i=0;i<n;i++)
            if(lvl[i]==inf)return 0;
        return 1;
    }
};