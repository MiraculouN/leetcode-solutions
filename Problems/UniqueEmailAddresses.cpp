/*
 * @lc app=leetcode id=1942997179 lang=cpp
 *
 * UniqueEmailAddresses
 * 
 * Difficulty: Easy
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string, int>mp;
        for(auto itr:emails){
            string s = itr;
            int plus=0, at=0;
            string s2;
            for(auto it:s){
                if(at ){
                    s2 +=it;
                    continue;
                }
                if(it =='@'){
                    s2+=it;
                    at =1;
                    continue;
                }
                if(plus)continue;
                if(it== '.')continue;
                if(it=='+'){
                    plus = 1;
                    continue;
                }
                else s2 +=it;
            }
            mp[s2]++;
        }
       /// for(auto it: mp)cout<<it.first<<endl;
        return mp.size();
    }
};