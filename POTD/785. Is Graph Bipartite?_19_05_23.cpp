class Solution {
public:
bool dfs(int node,vector<vector<int>>& graph,vector<int>&color,int cl){
    color[node] = cl;

    for(auto x: graph[node]){
        if(color[x]==-1){
            if(dfs(x,graph,color,!cl)==false)return false;
        }
        else if(color[x]==cl)return false;

    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();

        vector<int>color(n,-1);
        int cl=0;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,graph,color,cl)==false)
                return false;
            }

        }
        return true;
    }
};
