/*
 * @lc app=leetcode id=1933154903 lang=cpp
 *
 * BagOfTokens
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int n=tokens.size();
        int score=0, ans=0, i=0, j=n-1;
        while(i<=j){
            if(power >= tokens[i]){
                /// face-up;
                score++;
                power -= tokens[i];
                i++;
                ans = max(ans, score);
            }
            else{
                ///face_down
                if(score <1)break;
                score--;
                power+= tokens[j];
                j--;
            }
        }
        return ans;
    }
};