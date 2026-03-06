/*
 * @lc app=leetcode id=1939869285 lang=cpp
 *
 * GenerateParentheses
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    vector<string>ret;
    string cur;
    int cnt=0;
    int len;

    void fun(){
        if(cnt <0)return ;
        if(cur.length()==len){
            if(cnt ==0){
                ret.push_back(cur);
            }
            return ;
        }

        // do : (
        cur+= '(';
        cnt ++;
        fun();

        cur.pop_back();
        cnt --;


        /// do : )
        cur += ')';
        cnt--;
        fun();

        cur.pop_back();
        cnt++;
    }
    vector<string> generateParenthesis(int n) {
        len = 2*n;

        fun();
        return ret;

    }
};