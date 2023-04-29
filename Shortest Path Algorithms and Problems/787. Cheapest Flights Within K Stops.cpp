class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);

        for(int i = 0; i<flights.size() ; i++){

            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            adj[u].push_back({v,price});
        }
        
       vector<int>dis(n,1e9);
       queue<pair<int,pair<int,int>>>q;

       dis[src] = 0;

       q.push({0,{src,0}});

       while(!q.empty()){
           auto it = q.front();
           int stops = it.first;
           int node = it.second.first;
           int cost = it.second.second;

                q.pop();

           if(stops>k) continue;

           for(auto x: adj[node]){
               int child = x.first;
               int c = x.second;

               if(cost + c <dis[child]  && stops <= k){
                   dis[child] = cost + c;
                   q.push({stops+1,{ child,dis[child]}});
               }
           } 
       }

       if(dis[dst] == 1e9){
           return -1;
       }
       return dis[dst];


    }
};
