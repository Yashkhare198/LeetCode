class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {

    vector<vector<pair<int,int>>>ans(n+1);

        for(int i=0;i<roads.size();i++)
        {
            ans[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            ans[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
      int src=1;
      int des=n;
      vector<int>vis(n+1,0);
     
      queue<int>q;
     q.push(src);
      vis[src]=1;
int score=INT_MAX;
      while(!q.empty()){
          int node=q.front();
          q.pop();

          for(auto x:ans[node]){
              score=min(score,x.second);
             cout<<score<<" ";

             if(vis[x.first]==0)
             {  
                 vis[x.first]=1;
                    q.push(x.first);
             }

              }
          
      }

return score;
    }
};
