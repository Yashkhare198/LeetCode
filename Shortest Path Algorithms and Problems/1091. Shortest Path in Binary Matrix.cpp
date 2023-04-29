class Solution {
public:
  const int dx[8] = {-1,-1,0,1,1,1,0,-1};
  const int dy[8] = {0,1,1,1,0,-1,-1,-1};
bool bound(int i,int j,int n,int m){
    if(i>=0 && i<=n-1 && j>=0 && j<=m-1) return true;

    return false;
}
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         
        int n=grid.size();
        int m= grid[0].size();

        if(grid[0][0]==1 || grid[n-1][n-1]==1){
            return -1;
        }

        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dis(n,vector<int>(m,1e9));

        queue<pair<pair<int,int>,int>>q;

        q.push({{n-1,n-1},1});
        vis[n-1][n-1] = 1;
        dis[n-1][n-1] = 1;
 bool found=false;
        while(!q.empty()){
            auto node = q.front();
            int r = node.first.first;
            int c = node.first.second;
            int d = node.second;
             q.pop();
           for(int i=0;i<8;i++){
               int nexti = dx[i]+r;
               int nextj = dy[i]+c;

               if(bound(nexti,nextj,n,m)==true && vis[nexti][nextj]==0 &&grid[nexti][nextj]==0){
                   vis[nexti][nextj]= 1;
                    dis[nexti][nextj]=d+1;
                    q.push({{nexti,nextj},d+1});
                   if(nexti == 0 && nextj ==0){
                       found= true;
                      break;
                   }
               }
           }
           if(found == true){
               break;
           }

         


        }
          if(dis[0][0]==1e9){
               return -1;
           }
           return dis[0][0];

        
    }
};
