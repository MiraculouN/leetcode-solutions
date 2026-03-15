/*
 * @lc app=leetcode id=1947861008 lang=cpp
 *
 * TheKThLexicographicalStringOfAllHappyStringsOfLengthN
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */



class Solution {
public:
    string getHappyString(int n, int k) {
        long long  cnt=3;
        for(int i=2;i<=n; i++) 
            cnt*=2; 
        string ans=""; 
        if(k> cnt) 
            return ans; 
        if(k>(cnt/3)*2) 
            ans+='c', k-=(cnt/3*2); 
        else if(k> cnt/3)
            ans+='b', k-=(cnt/3); 
        else ans+='a'; 
        cnt/=3;
           for(int i=1;i<n; i++){
               if(k<=cnt/2){ 
            if(ans.back()=='a') 
            ans+='b';
               else ans+='a';} 

        else if(ans.back()=='c') 
            ans+='b', k-=(cnt/2); 
               else ans+='c', k-=(cnt/2); 
               

        cnt/=2;
               
           } 
        return ans; 
    }
};