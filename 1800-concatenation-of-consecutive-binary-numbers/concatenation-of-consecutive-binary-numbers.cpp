class Solution {
public:
    const int N=1e9+7;
    int concatenatedBinary(int n) {
        long long int ans =0;
        for(int i=1;i<=n;i++){
            long long int x = i, cnt=1;
            while(x){
                cnt=(cnt * 2)%N;
                x/=2;
            }
            ans = (ans * cnt)%N;
            ans = (ans + i)%N;
        }
        return ans;
    }
};