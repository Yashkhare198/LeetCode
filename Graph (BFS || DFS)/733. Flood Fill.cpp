// Approach 1 (Using BFS)

class Solution {
public:

const int dx[4]={-1,0,1,0};
const int dy[4]={0,1,0,-1};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       
       int n = image.size();
       int m = image[0].size();

        queue<pair<int,int>>q;

        vector<vector<int>>vis(n,vector<int>(m));
         int orig=image[sr][sc];
        q.push({sr,sc});
        vis[sr][sc]=color;
        image[sr][sc]=color;
        while(!q.empty()){
            auto x=q.front();
            int r=x.first;
            int c=x.second;
            q.pop();

            for(int i=0;i<4;i++){
                int nexti=r+dx[i];
                int nextj=c+dy[i];
                if(nexti>=0 &&nexti<n &&nextj>=0 &&nextj<m && vis[nexti][nextj]!=color &&image[nexti][nextj]==orig){
                    vis[nexti][nextj]=color;
                    image[nexti][nextj]=color;
                    q.push({nexti,nextj});
                }
            }
        }
        return image;
    }
};


//Approach 2 (Using DFS)

class Solution {
public:

void flood(int i,int j,vector<vector<int>>& image, int oldColor,int newColor,int n,int m)
{
     if(i<0 || j<0 || i==n ||j==m || image[i][j]!=oldColor) return;

     image[i][j] =newColor;
     flood(i+1,j,image,oldColor,newColor,n,m);
      flood(i-1,j,image,oldColor,newColor,n,m);
       flood(i,j+1,image,oldColor,newColor,n,m);
        flood(i,j-1,image,oldColor,newColor,n,m);
    

}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldColor = image[sr][sc];
        if(oldColor==color) return image;
int n=image.size();
int m=image[0].size();
        flood(sr,sc,image,oldColor,color,n,m);
        return image;
        
    }
};
