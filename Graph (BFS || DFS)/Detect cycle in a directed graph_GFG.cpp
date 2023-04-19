class Solution {
  public:
  int a;
  
  bool dfs(vector<int> *adj,int node,vector<int>&vis,vector<int>&pathVis){
      vis[node]=1;
      pathVis[node]=1;
      for(auto x:adj[node]){
          if(!vis[x]){
              if(dfs(adj,x,vis,pathVis)==true){
                  return true;
              }
          }
          else if(pathVis[x]){
              return true;
          }
      }
      pathVis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
         vector<int>pathVis(V,0);
        a=V;
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis)==true)
                return 1;
            }
        }
        return 0;
    }
};
