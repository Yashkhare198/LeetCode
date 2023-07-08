//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	
	int sum(int idx,int *arr,int dp[])
	{
	    if(idx == 0) return arr[idx];
	    
	    if(idx<0) return 0;
	    
	    if(dp[idx] != -1) return dp[idx];
	    
	    int pick = arr[idx]+ sum(idx-2,arr,dp);
	    
	    int notPick = 0 + sum(idx-1,arr,dp);
	    
	    return dp[idx] = max(pick,notPick);
	}
	int findMaxSum(int *arr, int n) {
	    // code here
	   // vector<int>dp(n,-1);
	    int dp[n];
	    
	    fill(dp,dp+n,-1);
	   int ans =  sum(n-1,arr,dp);
	   
	   return ans;
	   
	   
	    
	}
};
