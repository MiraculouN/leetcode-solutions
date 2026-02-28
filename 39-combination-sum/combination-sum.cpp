class Solution {
public:
    int sum =0, t, n;
    vector<int>cur;
    vector<vector<int>>ret;
    vector<int>v;

    void fun(int idx){
        if(sum > t)return ;
        if(idx==n){
            if(sum == t)ret.push_back(cur);
            return ;
        }
        /// take v[idx] (do)
        sum += v[idx];
        cur.push_back(v[idx]);
        fun(idx);
        ///leave v[idx]; (undo)

        sum -= v[idx];
        cur.pop_back();
        fun(idx+1);

    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        t = target;
        v=c;
        n = c.size();
        fun(0);
        return ret;
    }
};