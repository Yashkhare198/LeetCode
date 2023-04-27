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


// Approach 2(Using Toposort DFS)

  void toposort(int node , vector<int>&vis ,vector<vector<pair<int,int>>>&adj ,stack<int>&st){
      
      vis[node] = 1;
      
      for(auto x: adj[node]){
          int v = x.first;
        //   int wt = x.second;
          if(!vis[v]){
              toposort(v,vis,adj,st);
          }
      }
      st.push(node);
  }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
          
          vector<vector<pair<int,int>>>adj(N);
          
          for(int i = 0; i<M ;i++)
          {
              int u = edges[i][0];
              int v = edges[i][1];
              int wt = edges[i][2];
              
              adj[u].push_back({v,wt});
          }
          
          vector<int>vis(N,0);
          stack<int>st;
          
          for(int i=0;i<N;i++){
              if(!vis[i]){
                  toposort(i,vis,adj,st);
              }
          }
          vector<int>dis(N,1e9);
          dis[0] = 0;
          while(!st.empty())
          {
              int node = st.top();
              st.pop();
              
              for(auto it: adj[node]){
                  int v = it.first;
                  int wt = it.second;
                  
                  if(dis[node]+wt < dis[v] ){
                      dis[v] =dis[node] + wt;
                  }
              }
              
          }
          
          for(int i = 0 ; i<N ;i++){
              if(dis[i] == 1e9){
                  dis[i] = -1;
              }
          }
          return dis;
    }
};
