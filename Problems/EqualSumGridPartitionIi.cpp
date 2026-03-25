/*
 * @lc app=leetcode id=1958982579 lang=cpp
 *
 * EqualSumGridPartitionIi
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int M = 100001;
        int n = grid.size(), m = grid[0].size();
        vector<ll>pre(n);
        map<int,int>mp, mp2;
        for(int i=0;i<n;i++){
            ll cnt=0;
            for(int j=0;j<m;j++){
                cnt += grid[i][j];
                mp2[grid[i][j]]++;

            }
            if(!i){
                pre[i] = cnt;
            }
            else{
                pre[i] = pre[i-1]+cnt;
   
            }
        }
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                int x = grid[i][j];
                mp2[x]--;
                if(!mp2[x])mp2.erase(x);
                mp[grid[i][j]]++;
            }
            ll s1 = pre[i] , s2 = pre[n-1] - pre[i];
            if(s1 == s2)return 1;
            if(i==0 && s1 > s2){
                if(s1 - grid[0][0]==s2)return 1;
                if(s1 - grid[0][m-1]==s2)return 1;
            }
            if(i && s1 > s2){
                if(m!=1){
                    ll d = s1- s2;
                    if(d<M && mp[d])return 1;
                }
                else{
                    if(s1 - grid[i][0]==s2)return 1;
                    if(s1 - grid[0][0]==s2)return 1;
                }
            }
            if(i==n-2 && s2 > s1){
                if(s2 - grid[n-1][0]==s1)return 1;
                if(s2-grid[n-1][m-1]==s1)return 1;
            }
            if(i!=n-2 && s2>s1){
                if(m!=1){
                    ll d  = s2 -s1;
                    if(d<M && mp2[d])return 1;
                }
                else{
                    if(s2 - grid[i+1][0]==s1)return 1;
                    if(s2 - grid[n-1][0]==s1)return 1;
                }
            }

        }


        pre.assign(m, 0);
        mp.clear();
        mp2.clear();

        for(int j=0;j<m;j++){
            ll cnt=0;
            for(int i=0;i<n;i++){
                cnt += grid[i][j];
                mp2[grid[i][j]]++;
            }
            if(!j){
                pre[j]=cnt;
            }
            else{
                pre[j] = pre[j-1]+ cnt;
            }
        }
        
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                int x = grid[i][j];
                mp2[x]--;
                if(!mp2[x])mp2.erase(x);
                mp[x]++;
            }
            ll s1 = pre[j], s2 = pre[m-1]-pre[j];
            if(s1==s2)return 1;

            if(j==0 && s1>s2){
                if(s1 - grid[0][0]==s2)return 1;
                if(s1 - grid[n-1][0]==s2)return 1;
            }
            if(j && s1 > s2){
                if(n!=1){
                    ll d = s1 -s2;
                    if(d<M && mp[d])return 1;
                }
                else{
                    if(s1 - grid[0][j]==s2)return 1;
                    if(s1- grid[0][0]==s2)return 1;
                }
            }
            if(j==m-2 && s2>s1){
                if(s2 - grid[0][m-1]==s1)return 1;
                if(s2 - grid[n-1][m-1]==s1)return 1;

            }
            if(j!=m-2 && s2>s1){
                if(n!=1){
                    ll d = s2 - s1;
                    if(d<M && mp2[d])return 1;
                }
                else{
                    if(s2 - grid[0][m-1]==s1)return 1;
                    if(s2 - grid[0][j+1]==s1)return 1;
                }
            }


        }
        
        return 0;

    }
};