//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void bfs(int src,vector<vector<int>>&ans,vector<int>&vis,queue<int>&q){
      
      q.push(src);
      vis[src]=1;
      
      while(!q.empty()){
          int node=q.front();
          q.pop();
          for(auto it:ans[node]){
              if(!vis[it]){
                  q.push(it);
                  vis[it]=1;
              }
          }
      }
  }
  
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        vector<vector<int>>ans(V+1);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(i!=j  && adj[i][j]==1){
                    ans[i+1].push_back(j+1);
                    ans[j+1].push_back(i+1);
                }
            }
        }
        
        vector<int>vis(V+1,0);
        
        queue<int>q;
        int count=0;
        
        for(int i=1;i<=V;i++){
            if(vis[i] == 0){
                count++;
                bfs(i,ans,vis,q);
            }
        }
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
