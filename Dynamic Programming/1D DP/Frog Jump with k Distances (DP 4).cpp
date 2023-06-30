class Solution {
  public:
  
  int f(int ind,vector<int>&height,int k,vector<int>&dp){
      
      if(ind == 0) return 0;
      
      if(dp[ind] != -1) return dp[ind];
      
     int minSteps = INT_MAX;
     
     for(int j = 1; j<=k ; j++){
         
         if(ind-j >= 0){
             int jump = f(ind-j,height,k,dp) + abs(height[ind] - height[ind-j]);
         
         minSteps = min(jump,minSteps);
         }
     }
     return dp[ind] = minSteps;
  }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        
        vector<int>dp(n,-1);
        
        return f(n-1,height,k, dp);
    }
};
