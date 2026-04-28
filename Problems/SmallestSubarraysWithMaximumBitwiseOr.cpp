/*
 * @lc app=leetcode id=1990322236 lang=cpp
 *
 * SmallestSubarraysWithMaximumBitwiseOr
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& v) {
        int n=v.size();
       
        vector<vector<int>>nxt(31, vector<int>(n, 0));
      
        for(int b=0;b<=30;b++){
            if(v[n-1] & (1<<b))nxt[b][n-1]=n-1;
            for(int i=n-2;i>=0;i--){
                if(v[i] & (1<<b))nxt[b][i]=i;
                else nxt[b][i]=nxt[b][i+1];
            }
        }


        vector<int>ans;
        for(int i=0;i<n;i++){
            int len=1;
            for(int b=0;b<=30;b++){
                int j=nxt[b][i];
                len=max(len, j-i+1);
            }
            ans.push_back(len);
        }
        return ans;

    }
};