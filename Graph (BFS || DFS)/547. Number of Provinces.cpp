class Solution {
public:

void bfs(int src,vector<vector<int>>&adj,vector<int>&vis){

    queue<int>q;
    q.push(src);
    vis[src]=1;

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(auto x:adj[a]){
            if(vis[x]==0){
                vis[x]=1;
                q.push(x);
            }
        }
    }


}

int findCircleNum(vector<vector<int>>& isConnected) {

        vector<vector<int>>adj(isConnected.size());

        for(int i=0;i<isConnected.size();i++){

            for(int j=0;j<isConnected[i].size();j++){
                if(i!=j  && isConnected[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
                }

            }
        }
        int n=adj.size();
       
    
        vector<int>vis(n,0);
        int count=0;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                count++;
               bfs(i,adj,vis);
               
            }

        }
        return count;
        
    }
};
