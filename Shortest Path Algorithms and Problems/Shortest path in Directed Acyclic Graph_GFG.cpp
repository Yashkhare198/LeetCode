// Approach 1 (Using Normal BFS variation)

class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
          vector<int>dis(N,-1);
        vector<int>vis(N,0);
      vector<vector<pair<int,int>>>adj(N);
        
        for(auto x:edges){
            adj[x[0]].push_back({x[1],x[2]});
          
        }
        
        queue<pair<int,int>>q;
        int src=0;
        dis[src]=0;
        vis[src]=1;
        
        q.push({src,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            for(auto x: adj[node]){
                int child= x.first;
                int di=x.second;
                if(!vis[child]){
                    vis[child]=1;
                    dis[child]=dist+di;
                    q.push({child,dis[child]});
                }
                else {
                    dis[child] = min(dis[child], dist + di);
                }
            }
        }
        return dis;
    }
};
