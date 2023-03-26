class Solution {
public:

int bfs(int i,vector<int>&vis,vector<int>adj[])
{int count=0;
queue<int>q;
vis[i]=1;
q.push(i);

while(!q.empty())
{
    int a=q.front();
    q.pop();
  count++;
    for(auto x:adj[a])
    {
        if(!vis[x])
        {
            vis[x]=1;
            q.push(x);
        }
    }
}
return count;
}

    long long countPairs(int n, vector<vector<int>>& edges) {

        long long ans=0,total=n;

        vector<int>adj[n];

        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);

        for(int i =0; i<n ;i++){
            if(!vis[i]){
                int cnt = bfs(i,vis,adj);
                ans+=(total-cnt)*cnt;

            }
        }
        return ans/2;
    }
};
