class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
         vector<int>indegree(n,0);
        vector<vector<int>>adj(n);
        for(int i=0;i<pre.size();i++){
            indegree[pre[i][0]]++;
            adj[pre[i][1]].push_back(pre[i][0]);
        }
         queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        int cnt = 0;
          vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
              topo.push_back(node);
            cnt++;

            for(auto child : adj[node]){
                indegree[child]--;
                if(indegree[child] == 0){
                    q.push(child);
                }
            }
        }

        if(topo.size() == n) return topo;

        return {};
    }
};
