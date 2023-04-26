class Solution{
    
    vector<int> toposort(int V,vector<vector<int>>&adj){
        vector<int>indegree(V,0);
        
        for(int i=0;i<adj.size();i++){
            for(auto x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]== 0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto child:adj[node]){
                indegree[child]--;
                if(indegree[child]==0){
                    q.push(child);
                }
            }
        }
        return topo;
    }
    public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K);
        for(int i = 0; i<N-1;i++){
            
            string s1= dict[i];
            string s2 = dict[i+1];
            
            int len =min(s1.size(),s2.size());
            
            for(int p =0; p<len ; p++){
                if(s1[p]!=s2[p]){
                    adj[s1[p]-'a'].push_back(s2[p]-'a');
                    break;
                }
            }
        }
        vector<int>topo= toposort(K,adj);
        string s="";
        for(auto x:topo){
            
            s=s+char(x+'a');
        }
        return s;
    }
