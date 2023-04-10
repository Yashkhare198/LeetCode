class Solution {
public:
bool isCyclic(vector<vector<int>>&adj,vector<int>&vis,int curr)
{
    if(vis[curr]==2) return true;

    vis[curr]=2;

    for(int i=0;i<adj[curr].size();i++){
        if(vis[adj[curr][i]]!=1){
            if(isCyclic(adj,vis,adj[curr][i])) return true;
        }
      
    }
      vis[curr]=1;
        return false;
   
}

    bool containsCycle(vector<vector<int>>&adj,int n){
         
         vector<int>vis(n,0);

         for(int i=0;i<n;i++){
             if(vis[i]==0){
                 if(isCyclic(adj,vis,i)) return true;
             }
         }
       return false;
     }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        
         int n = colors.length();

         vector<vector<int>>adj(n);

         for(int i=0; i<edges.size();i++){
             adj[edges[i][0]].push_back(edges[i][1]);
         }

         if(containsCycle(adj,n)) return -1;

         vector<int>indegree(n,0);

         for(auto x:edges){
             indegree[x[1]]++;
         }

         vector<vector<int>>count(n,vector<int>(26,0));

         queue<int>q;

         for(int i=0;i<n;i++){

             if(indegree[i]==0){
                 q.push(i);
                 count[i][colors[i]-'a']++;
             }
         }

      int ans=0;
      while(!q.empty()){
          int node=q.front();
          q.pop();

          int r=*max_element(count[node].begin(),count[node].end());

          ans=max(ans,r);

          for(auto x:adj[node]){
              for(int i=0;i<26;i++){
                  count[x][i]=max(count[x][i],count[node][i]+(i==colors[x]-'a'));
              }
                  if(--indegree[x]==0){
                      q.push(x);
                  
              }
          }
      }    
return ans;

    }
};
