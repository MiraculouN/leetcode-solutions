class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>v(2005, 1005);
        v[2] = -1;
        for(int i=2;i<1005;i++){
            int x = i | (i-1);
            v[x] = min(v[x], i-1);
        }
        vector<int>ans;
        for(auto it:nums){
            ans.push_back(v[it]);
        }
        return ans;
    }
};