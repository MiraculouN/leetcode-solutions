/*
 * @lc app=leetcode id=1945530111 lang=cpp
 *
 * MaximizeSpanningTreeStabilityWithUpgrades
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    struct DSU{
        vector<int>leader,edges,Gsize,min_node,max_node,min_edge;
        int no_of_components=0;
        void init(int n){
            leader.assign(n+10,0);
            Gsize.assign(n+10,1);
            edges.assign(n+10,0);
            no_of_components = n;
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
            no_of_components --;
            ///min_edge[min(l_a,l_b)]=min({min_edge[min(l_a,l_b)],min_edge[max(l_a,l_b)],w});
            ///min_node[l_a]=min(min_node[l_b],min_node[l_a]);
            ///max_node[l_a]=max(max_node[l_b],max_node[l_a]);

        }

    };
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        DSU dsu;
        dsu.init(n);
        vector<pair<int, pair<int,int>>>vp;
        int ans = 1e9;
        for(auto it:edges){
            int a = it[0], b= it[1], c = it[2], m= it[3];
            if(m == 1){
                if(dsu.get_leader(a)==dsu.get_leader(b))return -1;
                dsu.union_find(a, b);
                ans = min(ans, c);
            }
            else{
                vp.push_back({c, {a,b}});
            }
        }
        sort(vp.begin(), vp.end(), greater<pair<int,pair<int,int>>>());
        priority_queue<int>pq;
        for(auto it:vp){
            int a = it.second.first;
            int b =it.second.second;
            int c = it.first;
            if(dsu.get_leader(a)!=dsu.get_leader(b)){
                pq.push(-c);
                dsu.union_find(a, b);
            }
        }
        while(!pq.empty()){
            int x = pq.top() * -1;
            pq.pop();
            if(k){
                x *=2;
                ans = min(ans, x);
                k--;
            }
            else ans = min(ans, x);

        }
        if(dsu.no_of_components!=1)return -1;
        return ans;
    }
};