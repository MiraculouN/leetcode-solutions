/*
 * @lc app=leetcode id=1988570642 lang=cpp
 *
 * MinimizeHammingDistanceAfterSwapOperations
 * 
 * Difficulty: Medium
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    struct DSU{
        vector<int>leader,edges,Gsize,min_node,max_node,min_edge;
        void init(int n){
            leader.assign(n+10,0);
            Gsize.assign(n+10,1);
            edges.assign(n+10,0);
            for(int i=1;i<=n;i++)leader[i]=i;

        }
        int get_leader(int node){
            return (leader[node]==node)?node:leader[node]=get_leader(leader[node]);
        }
        void union_find(int a,int b){
            if(get_leader(a)== get_leader(b)){
                edges[get_leader(b)]++;
                return;
            }
            int l_a=get_leader(a);
            int l_b=get_leader(b);
            if(Gsize[l_a]<Gsize[l_b]){
                edges[l_b]+=1+edges[l_a];
                Gsize[l_b]+=Gsize[l_a];
                leader[l_a]=l_b;
            }
            else{
                edges[l_a]+=1+edges[l_b];
                Gsize[l_a]+=Gsize[l_b];
                leader[l_b]=l_a;
            }
        }

    };
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu;
        dsu.init(n);
        for(auto it:allowedSwaps){
            int a = it[0], b =  it[1];
            dsu.union_find(a, b);
        }
        vector<multiset<int>>v(n), v1(n);
        for(int i=0;i<n;i++){
            v[dsu.get_leader(i)].insert(source[i]);
            v1[dsu.get_leader(i)].insert(target[i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            int mismatch = v[i].size();
            for(auto it:v[i]){
                if(v1[i].find(it)!=v1[i].end()){
                    v1[i].erase(v1[i].find(it));
                    mismatch--;
                }
            }
            ans += mismatch;
        }
        return ans;
    }
};