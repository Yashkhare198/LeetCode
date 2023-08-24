//Approach 1(Memoization)

class Solution {
public:

    int path(vector<vector<int>>&triangle,vector<vector<int>>&dp,int i,int j,int n)
    {
        if(i==n-1) return triangle[n-1][j];

        if(dp[i][j] != -1) return dp[i][j];

        int d = triangle[i][j] + path(triangle,dp,i+1,j,n);
        int dg = triangle[i][j]+path(triangle,dp,i+1,j+1,n);

        return dp[i][j] = min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {

        int n = triangle.size();
        // int m = triangle[0].size();

        vector<vector<int>>dp(n,vector<int>(n,-1));

        return path(triangle,dp,0,0,n);


        
    }
};

//Approach 2(Tabulation)

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n = triangle.size();

        vector<vector<int>>dp(n,vector<int>(n,0));

        for(int i = 0; i<n ; i++) dp[n-1][i] = triangle[n-1][i];


        for(int i = n-2; i>=0 ;i--)
        {
            for(int j = i;j>=0;j--)
            {
                int d = triangle[i][j]+dp[i+1][j];
                int dg = triangle[i][j]+dp[i+1][j+1];

                dp[i][j] = min(d,dg);
            }
        }
        return dp[0][0];
    }
};
