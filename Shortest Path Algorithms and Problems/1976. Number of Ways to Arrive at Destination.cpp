class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair< int,int>>>adj(n);
long long int mod = (long long int)(1e9 + 7);
        for(int i = 0; i<roads.size() ;i++){
           int u =  roads[i][0];
          int v = roads[i][1];
         int t = roads[i][2];

            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
          vector<long long> dis(n, 1e15), ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;

        pq.push({0,0});

        while(!pq.empty()){
              auto itr = pq.top();
            int node = itr.second;
             long long   dist =itr.first;
              pq.pop();
              for(auto x: adj[node]){

               int child =  x.first;
                 long long   d =x.second;

                  if(dist + d < dis[child]){
                      dis[child] = dist + d;
                      pq.push({dis[child],child});
                      ways[child] = ways[node];
                  }
                  else if(dist +d == dis[child]){
                         ways[child] = (ways[child]+ways[node])%mod;
                  }
              }

        }

        return ways[n-1]%mod;
       
    }
};
