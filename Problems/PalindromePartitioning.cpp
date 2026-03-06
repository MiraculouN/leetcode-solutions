/*
 * @lc app=leetcode id=1939880491 lang=cpp
 *
 * PalindromePartitioning
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int is_pal(string  s){
        string s2=s;
        reverse(s2.begin(), s2.end());
        return (s==s2);

    }


    vector<string>cur;
    vector<vector<string>>ret;

    string s;
    void fun(int idx){

        if(idx==s.length()){
            ret.push_back(cur);
            return ;
        }


        string s2;
        for(int i=idx;i<s.length();i++){
            s2+=s[i];
            if(is_pal(s2)){
                cur.push_back(s2);
                fun(i+1);

                cur.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s2) {
        s=s2;
        fun(0);
        return ret;
    }
};