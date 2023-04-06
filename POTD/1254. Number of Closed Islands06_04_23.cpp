class Solution {
public:
  const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
bool bound(int i, int j, int r, int c){
  

    if(i!=0 && j!=c-1  && i!=r-1 && j!=0) return true;

    return false;
}

    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int cnt = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0  && bound(i,j,r,c)){

                    queue<pair<int,int>>q;
                    q.push({i,j});
                    grid[i][j]=2;
                    bool found = false;

                    while(!q.empty()){
                        auto node =q.front();
                        q.pop();

                        for(int x=0;x<4;x++){
                            int nexti = node.first+dx[x];
                            int nextj = node.second+dy[x];

                            if(nexti>=0 && nextj>=0 &&nexti<r &&nextj<c && grid[nexti][nextj]==0){
                                grid[nexti][nextj]=2;
                                q.push({nexti,nextj});
                                if(!bound(nexti,nextj,r,c)) found = true;
                            }
                        }


                    }
                    if(found==false) cnt++;
                   
                }
                
            }
        }
        return cnt;
    }
};
