//Approach 1(Using queue)

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // priority_queue<int,vector<int>,greater<int>> pq;
        
        vector<vector<pair<int,int>>>a(V);
        
        for(int i=0;i<V;i++){
            for(auto x:adj[i]){
                int u = i;
                int v = x[0];
                int wt = x[1];
                
                a[u].push_back({v,wt});
                a[v].push_back({u,wt});
            }
        }

        vector<int>dis(V,1e9);
        queue<pair<int,int>>q;
        dis[S]=0;
        q.push({S,0});
        
        while(!q.empty()){
            auto n = q.front();
            int node = n.first;
            // int dis = n.second;
            q.pop();
            for(auto x:a[node]){
                int child = x.first;
                int wt = x.second;
               if(dis[node]+wt<dis[child]){
                   dis[child]=dis[node]+wt;
                   q.push({child,dis[child]});
               }
            }
        }
        return dis;
        
    }
};

//Approach 2(Using priority_queue)

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
     
        vector<vector<pair<int, int>>> a(V);
        for (int i = 0; i < V; i++) {
            for (auto x : adj[i]) {
                int u = i;
                int v = x[0];
                int wt = x[1];
                a[u].push_back({v, wt});
                a[v].push_back({u, wt});
            }
        }
        
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        
        while (!pq.empty()) {
            auto n = pq.top();
            int node = n.second;
            int d = n.first;
            pq.pop();
            if (d > dis[node]) {
                continue;
            }
            for (auto x : a[node]) {
                int child = x.first;
                int wt = x.second;
                if (dis[node] + wt < dis[child]) {
                    dis[child] = dis[node] + wt;
                    pq.push({dis[child], child});
                }
            }
        }
        
        return dis;
    


    }
};
