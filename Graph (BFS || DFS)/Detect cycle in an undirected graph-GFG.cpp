class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool bfs(vector<int>&vis,int i,vector<int>adj[]){
        vis[i]=1;
        queue<pair<int,int>>q;
        q.push({i,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto x:adj[node]){
                if(!vis[x]){
                    vis[x]=1;
                    q.push({x,node});
                }
               else if(parent!=x){
                   return true;
               }
            }
        }
        return false;
        
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
       vector<int>vis(V,0);
       int cnt=0;
       for(int i=0;i<V;i++){
           if(!vis[i]){
              if (bfs(vis,i,adj))return true;
           }
           
       }
       return false;
    }
};
