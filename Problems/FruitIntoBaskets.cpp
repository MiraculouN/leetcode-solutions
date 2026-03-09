/*
 * @lc app=leetcode id=1942998118 lang=cpp
 *
 * FruitIntoBaskets
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int lo = 1, hi=n, mid, ans=0;
        
        auto can=[&](int m)->bool{
            map<int,int>mp;
            for(int i=0;i<m;i++){
                mp[fruits[i]]++;
            }
            if(mp.size()<=2)return 1;
            int i=0, j=m;
            while(j<n){
                mp[fruits[i]]--;
                if(!mp[fruits[i]])mp.erase(fruits[i]);
                mp[fruits[j]]++;
                i++, j++;
                if(mp.size()<=2)return 1;
            }
            
             return (mp.size()<=2);
        };
        
        while(lo<=hi){
            mid = lo+(hi-lo)/2;
            if(can(mid)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};