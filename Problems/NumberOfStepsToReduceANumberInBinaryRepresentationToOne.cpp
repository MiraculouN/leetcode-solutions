/*
 * @lc app=leetcode id=1933152876 lang=cpp
 *
 * NumberOfStepsToReduceANumberInBinaryRepresentationToOne
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        while(s!="1"){
            cnt++;
            if(s.back()=='0'){
                s.pop_back();
            }
            else{
                int n=s.length();
                int idx=n-1;
                while(idx>=0 && s[idx]=='1'){
                    s[idx]='0';
                    idx--;
                }
                if(idx==-1){
                    s="1"+s;
                }
                else
                s[idx]='1';
            }
        }
        return cnt;
    }
};