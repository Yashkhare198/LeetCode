//Approach 1(Memoization)

class Solution {
public:

int path(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>&dp)
{
    int n =matrix.size();
    if(j<0 || j>=n) 
    {
        return  1e5;
    }

    if(i == 0) return matrix[i][j];

    

    if(dp[i][j] != -101) return dp[i][j];

    int dl = matrix[i][j] + path(i-1,j-1,matrix,dp);
    int dc = matrix[i][j] + path(i-1,j,matrix,dp);
    int dr = matrix[i][j] + path(i-1,j+1,matrix,dp);

    return dp[i][j] = min(dl,min(dc,dr));


}
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        

        vector<vector<int>>dp(n,vector<int>(n,-101));
       int ans = INT_MAX;
        for(int i = 0; i<n ; i++)
        {
            ans = min(ans,path(n-1,i,matrix,dp));

        }
        return ans;
    }
};

//Approach 2(Tabulation)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int ans = INT_MAX;

        vector<vector<int>>dp(n,vector<int>(n));

        for(int i = 0; i < n ; i++)
        {
            dp[0][i] = matrix[0][i];
        }

        for(int i = 1;i<n ; i++)
        {
            for(int j = 0;j<n;j++)
            {
                int c = matrix[i][j] + dp[i-1][j];
                  int ld = INT_MAX, rd =INT_MAX;
                if(j-1 >= 0)
                {
                   ld =matrix[i][j]+ dp[i-1][j-1];
                }
               
                
                if(j+1 < n)
                {
                    rd =matrix[i][j] + dp[i-1][j+1];
                }
                
                dp[i][j] = min(c,min(ld,rd));
              
               
            }
             
           
        }

        for(int i = 0; i<n ; i++)
        {
            ans = min(ans,dp[n-1][i]);
        }

        return ans;
        
    }
};
