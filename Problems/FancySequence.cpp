/*
 * @lc app=leetcode id=1949494502 lang=cpp
 *
 * FancySequence
 * 
 * Difficulty: Hard
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

#define ll long long int
const int N=1e9+7;
ll fastPow(ll x, ll y, ll mode) {/// binary exponentiation
    x%=mode;
    long long res = 1;
    while (y > 0) {
        if (y % 2 == 1) { res = res * x %mode; }
        x = x * x %mode;
        y /= 2;
    }
    return res;

}

ll invMod(ll x, ll mode){
    return fastPow(x, mode-2 , mode);
}

class Fancy {
public:
    vector<pair<ll,ll>>vp;
    vector<ll>v;
    ll a , b;
    Fancy() {
        a =1;
        b =0;
    }
    
    void append(int val) {
        vp.push_back({a, b});
        v.push_back(val);
    }
    
    void addAll(int inc) {
        b += inc;
        b %=N;
    }
    
    void multAll(int m) {
        a = (a * m)%N;
        b = (b * m)%N;
    }
    
    int getIndex(int idx) {
        if(vp.size() <= idx)return -1;
        ll a_ = vp[idx].first ;
        ll b_ = vp[idx].second;

        ll A = a * invMod(a_, N)%N;
        ll B = (b - (b_ * A)%N + N)%N; 
        return (A*v[idx]%N + B)%N;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */