/*
 * @lc app=leetcode id=1990441196 lang=cpp
 *
 * MinimizeXor
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int on = __builtin_popcount(num2);
        int x=0;
        for(int bit = 31;bit >=0;bit--){
            /// cancel large bits
            if(on==0)break;
            if(num1 & (1<<bit)){
                x += (1<<bit);
                on--;
            }
        }
        for(int bit = 0;bit<32;bit++){
            /// cancel large bits
            if(on==0)break;
            if(!(num1 & (1<<bit))){
                x += (1<<bit);
                on--;
            }
        }
        return x;
        

    }
};