class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        
        vector<int>dis(N,-1);
        vector<int>vis(N,0);
        vector<vector<int>>adj(N);
        
        for(auto x:edges){
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        queue<pair<int,int>>q;
        
        dis[src]=0;
        vis[src]=1;
        
        q.push({src,0});
        
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            
            q.pop();
            
            for(auto x: adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    dis[x]=dist+1;
                    q.push({x,dis[x]});
                }
            }
        }
        return dis;
    }
};
