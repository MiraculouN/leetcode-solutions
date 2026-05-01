/*
 * @lc app=leetcode id=1992603958 lang=cpp
 *
 * WordLadder
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string, int>dist;
        map<string, int>mp;///dictionary

        for(auto it:wordList)mp[it]++;
        queue<string>q;
        q.push(beginWord);
        dist[beginWord]=1;

        while(!q.empty()){
            string s=q.front();q.pop();
            string str=s;
            for(int i=0;i<s.length();i++){
                for(char c='a';c<='z';c++){
                    if(s[i]==c)continue;
                    char tmp=s[i];
                    s[i]=c;
                    if(mp.count(s) && !dist.count(s)){
                        q.push(s); 
                        dist[s]=1+dist[str];
                        //str=>old string before changing ith character to c
                    }

                    s[i]=tmp;

                }
            }

        }

        if(!dist.count(endWord))return 0;
        return dist[endWord];



    }
};