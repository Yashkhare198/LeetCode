class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<vector<int>>ans(V);
      for(int i=0;i<V;i++){
          for(auto x:adj[i]){
              ans[i].push_back(x);
              
          }
      }
      
      int src=0;
      vector<int>vis(V,0);
      vector<int>a;
      queue<int>q;
      q.push(src);
      vis[src]=1;
      
      while(!q.empty()){
          int node=q.front();
          q.pop();
         a.push_back(node);
         
         for(auto child:ans[node])
         {
             if(vis[child]==0){
                 vis[child]=1;
                 q.push(child);
             }
         }
      }
      
      
      return a;
        
        
    }
};
