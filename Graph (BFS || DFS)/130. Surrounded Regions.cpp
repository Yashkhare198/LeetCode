class Solution {
public:
const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
bool bound(vector<vector<char>>&board,int n,int m,int i,int j){
    if(i==0 || i==n-1 || j==0 || j==m-1) return true;

    return false;;
}


    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i = 0;i < n; i++){
            for(int  j= 0;j< m ;j++){
                if(board[i][j]=='O' && (bound(board,n,m,i,j)==true)){
                    q.push({i,j});
                        vis[i][j]=1;
                }

            }
        }
        cout<<q.size();

        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nexti = r + dx[i];
                int nextj = c + dy[i];

                if(nexti>=0 && nexti<n &&nextj>=0 &&nextj<m &&vis[nexti][nextj]==0 && board[nexti][nextj]=='O' ){
                q.push({nexti,nextj});
                vis[nexti][nextj]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 ){
                    board[i][j]='X';
                }
            }
        }
        
    }
};
