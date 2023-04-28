class Solution{
public:
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

bool bound(int i, int j, int n , int m){
    
    if(i>=0 && i<=n-1 && j>=0 &&j<=m-1) return true;
    
    return false;
}

    vector<vector<int>> chefAndWells(int n,int m,vector<vector<char>> &c){
        // Code here
        vector<vector<int>>vis(n,vector<int>(m,0));
         vector<vector<int>>ans(n,vector<int>(m,-1));
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( c[i][j] =='N'){
                    ans[i][j] = 0;
                    vis[i][j] = 1;
                    // q.push({{i,j},0});
                }
                if(c[i][j]  == 'W'){
                    vis[i][j] = 1;
                    ans[i][j] = 0;
                    q.push({{i,j},0});
                }
                if(c[i][j] == '.'){
                    ans[i][j] = 0;
                }
            }
        }
        
        while(!q.empty()){
            
            int r = q.front().first.first;
            int ci = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            for(int i = 0 ;i<4 ;i++){
                int nexti = r+dx[i];
                int nextj = ci+dy[i];
                
                if(bound(nexti,nextj,n,m)==true && vis[nexti][nextj]==0 &&(c[nexti][nextj]=='H' ||c[nexti][nextj]=='.') )
            {
                    if(c[nexti][nextj]=='H') ans[nexti][nextj]=2*(dis+1);
                    
                        q.push({{nexti,nextj},dis+1});
                        vis[nexti][nextj]=1;
            }
                      
            }
            
        }
        return ans;
        
    }
};
