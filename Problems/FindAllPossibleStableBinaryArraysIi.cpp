/*
 * @lc app=leetcode id=1943454718 lang=cpp
 *
 * FindAllPossibleStableBinaryArraysIi
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
class Solution {
public:
    ll N=1e9+7;
    ll numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>>dp(one+10,vector<vector<int>>(zero+10,vector<int>(3,0)));
    vector<vector<int>>dp_sum1(one+10,vector<int>(zero+10,0));
    vector<vector<int>>dp_sum0(one+10,vector<int>(zero+10,0));
    for(int j=0;j<=zero;j++){
        dp[0][j][0]=(j>limit)?0:1;
        dp_sum0[0][j]+=dp[0][j][0];
        ///if(j)dp_sum0[0][j]+=dp_sum1[0][j-1];
    }
    for(int i=0;i<=one;i++){
        dp[i][0][1]=(i>limit)?0:1;
        dp_sum1[i][0]+=dp[i][0][1];
        ///if(i)dp_sum0[i][0]+=dp_sum0[i-1][0];
    }

    for(int i=1;i<=one;i++){
        for(int j=1;j<=zero;j++){
            dp[i][j][1]+=dp_sum0[i-1][j]%N;
            dp[i][j][1]%=N;
            if(i-limit-1>=0)
                dp[i][j][1]=(dp[i][j][1]-dp_sum0[i-limit-1][j]+N)%N;

            dp[i][j][0]+=dp_sum1[i][j-1];
            dp[i][j][0]%=N;
            if(j-limit-1>=0)
                dp[i][j][0]=(dp[i][j][0]-dp_sum1[i][j-limit-1]+N)%N;

            dp_sum0[i][j]=dp_sum0[i-1][j]+dp[i][j][0];
            dp_sum0[i][j]%=N;
            dp_sum1[i][j]+=dp_sum1[i][j-1]+dp[i][j][1];
            dp_sum1[i][j]%=N;
            /*
             dp[i][j][1]=dp[i-1][j][0]+dp[i-2][j][0]+dp[i-3][j][0]+....
             dp[i][j][0]=dp[i][j-1][1]+dp[i][j-2][1]+dp[i][j-3][1]+....
             */
        }

    }
    return (dp[one][zero][0]+dp[one][zero][1])%N;
            
    }
};