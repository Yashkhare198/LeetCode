//Aproach 1(Memoization)

class Solution {
public:

    int path(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j)
    {
        if(i == 0 && j ==0) return grid[i][j];
        if(i<0 || j<0) return 1e9;

        if(dp[i][j]!=1e9)return dp[i][j];

        int up = grid[i][j]+path(grid,dp,i-1,j);
        int left= grid[i][j]+path(grid,dp,i,j-1);


        return dp[i][j] = min(left,up);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>ans(n,vector<int>(m,1e9));


        return path(grid,ans,n-1,m-1);
        
    }
};

//Approach 2(Tabulation)

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n,vector<int>(m,0));

        for(int i = 0; i<n ; i++)
        {
            for(int j = 0; j<m ; j++)
            {
                    if(i == 0 && j == 0)dp[i][j] = grid[i][j];
                    else {
                        int up = grid[i][j];
                        if(i > 0) up += dp[i-1][j];
                        else  up += 1e9;

                        int left = grid[i][j];
                        if(j>0) left += dp[i][j-1];
                        else left += 1e9;

                        dp[i][j] = min(left,up);
                    }
            }
        }

        return dp[n-1][m-1];
    }
};
