class Solution {
  public:
  
  const int dx[4] = {-1,0,1,0};
  const int  dy[4] = {0,1,0,-1};
  
  bool bound(int i,int j,int n,int m){
      if(i<=n-1 && i>=0 &&j>=0 &&j<=m-1){
          return true;
      }
      return false;
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,int>>q;
        set<vector<pair<int,int>>>st;
        
        for(int i = 0; i<n ;i++){
            for(int j = 0; j<m ;j++){
                if(grid[i][j] == 1  && !vis[i][j]){
                    q.push({i,j});
                    vis[i][j] =1;
                    vector<pair<int,int>>v;
                    while(!q.empty())
                    {
                        int r=q.front().first;
                        int c=q.front().second;
                        q.pop();
                     pair<int,int>p={(i-r),(j-c)};
                     v.push_back({r-i,c-j});
                     
                     for(int k=0;k<4;k++){
                         int nexti = r+dx[k];
                         int nextj = c+dy[k];
                         if(bound(nexti,nextj,n,m)==true  &&vis[nexti][nextj]!=1 &&grid[nexti][nextj]==1){
                             q.push({nexti,nextj});
                             vis[nexti][nextj]=1;
                             
                         }
                     }
                     
                    }
                    st.insert(v);
                    v.clear();
                    
                    
                }
                
            }
        }
        
        return st.size();
    }
};
