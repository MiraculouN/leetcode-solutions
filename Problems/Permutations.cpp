/*
 * @lc app=leetcode id=1939819896 lang=cpp
 *
 * Permutations
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int n;
    vector<int>cur, used;
    vector<vector<int>>ret;
    vector<int>v;
    void generate_permutation(){
        if(cur.size()==n){
            ret.push_back(cur);
            return ;
        }
        for(int i=0;i<n;i++){
            if(!used[i]){
                cur.push_back(v[i]);
                used[i]=1;
                generate_permutation();

                cur.pop_back();
                used[i]=0;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        used.assign(n,0);
        v=nums;
        generate_permutation();
        return ret;
        //// used[i]=0 element nums[i] can be put in cur
    }
};