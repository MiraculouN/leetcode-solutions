/*
 * @lc app=leetcode id=1992581081 lang=cpp
 *
 * EscapeTheSpreadingFire
 * 
 * Difficulty: Level
 * Category: undefined
 * Runtime: N/A
 * Memory: N/A
 */

class Solution {
public:
    int n, m;
    int dx[4]={1, -1, 0 , 0};
    int dy[4]={0, 0 , -1, 1};
    vector<vector<int>>v, fire;
    int inf=2e9;

    int valid(int x, int y){
        return (x>=0 && x<n && y>=0 && y<m );
    }

    int can(int x){

        queue<pair<int,int>>q;
        vector<vector<int>>dist(n+1, vector<int>(m+1, inf));
        q.push({0,0});
        dist[0][0]=x;

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int n_x=x+dx[i];
                int n_y=y+dy[i];
                if(n_x==n-1 && n_y==m-1){
                    if(fire[n_x][n_y]>=1+dist[x][y])return 1;
                    return 0;
                }
                if(valid(n_x, n_y) && v[n_x][n_y]!=2 && dist[n_x][n_y]==inf && fire[n_x][n_y]>1+dist[x][y]){
                    dist[n_x][n_y]=1+dist[x][y];
                    q.push({n_x, n_y});
                }
            }
        }

        return dist[n-1][m-1]!=inf;

        
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        n=grid.size(), m=grid[0].size();
        v=grid;
        fire.assign(n+1, vector<int>(m+1, inf));

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]==1){
                    q.push({i,j});
                    fire[i][j]=0;
                }
            }

            
        }

        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;

            q.pop();

            for(int i=0;i<4;i++){
                int n_x=x+dx[i];
                int n_y=y+dy[i];
                if(valid(n_x, n_y) && v[n_x][n_y]!=2 && fire[n_x][n_y]==inf){
                    fire[n_x][n_y]=1+fire[x][y];
                    q.push({n_x, n_y});
                }
            }

        }

        int lo=0, hi=1e9 , mid, ans=-1;
        while(lo<=hi){
            mid=lo+(hi-lo)/2;
            if(can(mid)){
                /// check if person can reach safehouse when he moves at time x
                ans=mid;
                lo=mid+1;
            }
            else hi=mid-1;
        }

        return ans;



    }
};