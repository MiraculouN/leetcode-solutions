/*
 * @lc app=leetcode id=1993486932 lang=cpp
 *
 * RotatedDigits
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int isGood(int i){
        int flag=0;
        while(i){
            int x = i%10;
            if(x==3 || x==4 || x==7)return 0;
            if(x!=0 && x!=1 && x!=8){
                flag=1;
            }
            i/=10;
        }
        return flag;
    }
    int rotatedDigits(int n) {
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=isGood(i);
        }
        return cnt;
    }
};