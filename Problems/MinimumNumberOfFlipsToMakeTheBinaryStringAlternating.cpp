/*
 * @lc app=leetcode id=1941207119 lang=cpp
 *
 * MinimumNumberOfFlipsToMakeTheBinaryStringAlternating
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minFlips(string s) {
        int odd_zero=0, odd_one=0, even_zero=0, even_one=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(i&1){
                if(s[i]=='0')odd_zero++;
                else odd_one ++;
            }
            else{
                if(s[i]=='0')even_zero++;
                else even_one ++;
            }
        }
        int ans = n;
        for(int i=0;i<n;i++){
            if(s[i]=='1')even_one--;
            else odd_one --;
            swap(odd_one, even_one);
            swap(odd_zero, even_zero);
            if((n-1) %2==0){
                if(s[i]=='1')even_one++;
                else even_zero++;
            }
            else{
                if(s[i]=='1')odd_one++;
                else odd_zero++;
            }
            ans = min(ans, odd_zero+even_one);
            ans = min(ans, even_zero+odd_one);

        }
        return ans;
    }
};