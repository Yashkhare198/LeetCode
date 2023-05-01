
// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int>dis(V,1e8);
        dis[S] = 0;
      for(int i=0;i<V-1;i++){
          
          for(auto x: edges){
              int u = x[0];
              int v = x[1];
              int wt = x[2];
              
              if(dis[u] !=1e8 && dis[u] + wt <dis[v]){
                  dis[v] = dis[u] + wt;
              }
          }
      }
       for(auto x: edges){
              int u = x[0];
              int v = x[1];
              int wt = x[2];
              
              if(dis[u]!=1e8 && dis[u] + wt <dis[v]){
                  return {-1};
              }
          }
          return dis;
      
     
        
        
    }
};
