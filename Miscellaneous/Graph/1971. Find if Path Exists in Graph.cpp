class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
 vector<int> adjlist[n];
        for(int i=0;i< edges.size();i++){
            adjlist[edges[i][0]].push_back(edges[i][1]);
            adjlist[edges[i][1]].push_back(edges[i][0]);
        }

        vector<int>dis(n,-1);
        vector<int>vis(n,0);

        queue<int>q;
        q.push(source);
        vis[source]=1;
        dis[source]=0;

        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto x:adjlist[node])
            {
                if(vis[x]==0){
                    q.push(x);
                    vis[x]=1;
                    dis[x]=dis[node]+1;
                }
            }
        }
        if(vis[destination]==1){
            return true;
        }
        return false;
    }
};
