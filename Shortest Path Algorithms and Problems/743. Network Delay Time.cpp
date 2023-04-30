class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);

        for(int i = 0; i<times.size() ; i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adj[u].push_back({v,wt});
        }

        queue<pair<int,int>>q;

        vector<int>dis(n+1,1e9);
        dis[k]=0;

        q.push({k,0});

        while(!q.empty()){
             auto it = q.front();
             int node = it.first;
             int wt = it.second;

             q.pop();

             for(auto x:adj[node]){
                 int child = x.first;
                 int sig = x.second;

                 if(wt+sig < dis[child]){
                     dis[child] =wt +sig;
                     q.push({child,wt+sig});
                 }
             }


        }
        
int maxi=-1;
        for(int i=1;i<=n;i++){
            if(dis[i] == 1e9){
               
                return -1;
            }
            maxi=max(maxi,dis[i]);
        }
         
          return maxi;
       
    }
};
