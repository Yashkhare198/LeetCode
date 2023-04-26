class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
          int n= graph.size();
        vector<vector<int>>adj(n);
          vector<int>indegree(n,0);
        for(int i=0;i<n;i++){
            for (auto x:graph[i]){
               
                  adj[x].push_back(i);
                   indegree[i]++;
            }
        }
        
queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
         vector<int>topo;
        while(!q.empty()){
            int node =q.front();
            q.pop();
            topo.push_back(node);

            for(auto child:adj[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        sort(topo.begin(),topo.end());
        return topo;
       
        
    }
};
