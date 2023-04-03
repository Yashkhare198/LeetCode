
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node,vector<vector<int>>&a,vector<int>&ans,vector<int>&vis){
        vis[node]=1;
        ans.push_back(node);
        
        for(auto child:a[node]){
            if(vis[child]==0){
                dfs(child,a,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        // Code here
        vector<int>ans;
        
        vector<vector<int>>a(V);
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                a[i].push_back(x);
                 a[x].push_back(i);
            }
        }
        int src=0;
        vector<int>vis(V,0);
        
        dfs(src,a,ans,vis);
        return ans;
    }
};
