class Solution {
public:


         const int dx[4]={-1,1,0,0};
    const int dy[4]={0,0,-1,1};
     
    
    bool bound(int i,int j,int r,int c){
        if(i==0 ||j==0 || i==r-1 ||j==c-1){
            return true;
        }
        return false;
    }

   int numEnclaves(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        int total=0;
        int cnt=0;
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1)total++;
                if(grid[i][j]==1  && bound(i,j,r,c))
                { 
                   
                   cnt++;
                    q.push({i,j});
                     grid[i][j]=2;
                    
                   
                }
            }
        }
        while(!q.empty()){
                  
                        auto node=q.front();
                        q.pop();
                        
                        for(int x=0;x<4;x++){
                            int nexti=node.first+dx[x];
                            int nextj=node.second+dy[x];
                            if(nexti>=0 &&nexti<=r-1 &&nextj>=0 &&nextj<=c-1 && grid[nexti][nextj]==1)
                            {
                                
                               cnt++;
                                q.push({nexti,nextj});
                                 grid[nexti][nextj]=2;
                            }
                        }
                    }
        
  
       
        return total-cnt;
    }
};
