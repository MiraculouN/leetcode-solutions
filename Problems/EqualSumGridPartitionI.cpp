/*
 * @lc app=leetcode id=1958957727 lang=cpp
 *
 * EqualSumGridPartitionI
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        const int M = 100005;
        int n = grid.size(), m = grid[0].size();
        vector<ll>pre(n);
        vector<bitset<M>>mp(n), mp2(n);
        for(int i=0;i<n;i++){
            ll cnt=0;
            bitset<M>b;
            for(int j=0;j<m;j++){
                cnt += grid[i][j];
                b[grid[i][j]]=1;
            }
            if(!i){
                pre[i] = cnt;
                mp[i] = b;
            }
            else{
                pre[i] = pre[i-1]+cnt;
                mp[i] = b | mp[i-1];
            }
        }
        for(int i=n-1;i>=0;i--){
            bitset<M>b;
            for(int j=0;j<m;j++){
                b[grid[i][j]]=1;
            }
            if(i==n-1){
                mp2[i] = b;
            }
            else{
                mp2[i] = b | mp2[i+1];
            }
        }
        for(int i=0;i<n-1;i++){
            ll s1 = pre[i] , s2 = pre[n-1] - pre[i];
            if(s1==s2)return 1;
            if(pre[i]-grid[0][0]== pre[n-1]-pre[i])return 1;
            if(pre[i]-grid[0][m-1]== pre[n-1]-pre[i])return 1;
            if(pre[i]== pre[n-1]-pre[i]-grid[i+1][m-1])return 1;
            if(pre[i]== pre[n-1]-pre[i]-grid[i+1][0])return 1;
            if(m==1 && pre[i] == pre[n-1]-pre[i]-grid[i+1][0])return 1;
            if(m==1 && pre[i] == pre[n-1]-pre[i]-grid[n-1][0])return 1;
            
            if(m==1 && pre[i] - grid[i][0] == pre[n-1]-pre[i])return 1;

            if(m==1)continue;
            if(i && s1 > s2){
                ll d = s1 - s2;
                if(d< M && mp[i][d]==1)return 1;
            }
            if(i==0 && m!=1 && s1>s2){            
                ll d = s1 - s2;
                if(d<M && mp[i][d]==1)return 1;
            }
            if(i!=n-2 && s2>s1){
                int d = s2 - s1;
                if(d< M && mp2[i+1][d]==1)return 1;
            }

        }

        if(pre[0] - grid[0][0] == pre[n-1]-pre[0])return 1;
        if(pre[0] - grid[0][m-1] == pre[n-1]-pre[0])return 1;
        if(n>=2 && pre[n-1]-pre[n-2] - grid[n-1][0] == pre[n-2])return 1;
        if(n>=2 && pre[n-1]-pre[n-2] - grid[n-1][m-1] == pre[n-2])return 1;

        pre.assign(m, 0);
        mp.assign(m, bitset<M>());
        mp2.assign(m, bitset<M>());

        for(int j=0;j<m;j++){
            ll cnt=0;
            bitset<M>b;
            for(int i=0;i<n;i++){
                cnt += grid[i][j];
                b[grid[i][j]]=1;
            }
            if(!j){
                pre[j]=cnt;
                mp[j]=b;
            }
            else{
                pre[j] = pre[j-1]+ cnt;
                mp[j] = mp[j-1] | b;
            }
        }
        for(int j=m-1;j>=0;j--){
            bitset<M>b;
            for(int i=0;i<n;i++){
                b[grid[i][j]]=1;
            }
            if(j==m-1){
                mp2[j]=b;
            }
            else{
                mp2[j] = mp2[j+1] | b;
            }
        }

        
        for(int j=0;j<m-1;j++){
            ll s1 = pre[j], s2 = pre[m-1]-pre[j];
            if(s1==s2)return 1;
            
            if(pre[j]- grid[0][0]== pre[m-1]-pre[j])return 1;
            if(pre[j]- grid[n-1][0]== pre[m-1]-pre[j])return 1;

            if(n==1 && pre[j]- grid[0][j]== pre[m-1]-pre[j])return 1;
            if(n==1 && pre[j]== pre[m-1]-pre[j]-grid[0][j+1])return 1;
            if(n==1 && pre[j]== pre[m-1]-pre[j]-grid[0][m-1])return 1;


            if(pre[j] == pre[m-1]-pre[j]-grid[0][m-1])return 1;
            if(pre[j] == pre[m-1]-pre[j]-grid[n-1][m-1])return 1;


            if(n==1)continue;
            if(j!=0 && s1>s2){
                ll d = s1 - s2;
                if(d<M && mp[j][d]==1)return 1;
            }
            if(j==0 && n!=1 && s1>s2){            
                ll d = s1 - s2;
                if(d<M && mp[j][d]==1)return 1;
            }
            if(s2>s1 &&  j!=m-2){
                ll d= s2 - s1;
                if(d<M && mp2[j+1][d]==1)return 1;
            }



        }
        
       

        return 0;

    }
};