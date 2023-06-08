class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
   
   int cnt = 0;
    
    for(int i = 0; i<n ;i++){
        int s = 0;
        int e = m-1;
        
      int ans =0;
      int mid=0;
        while(s<=e)
        {
             mid = s + (e-s)/2;

            if(grid[i][mid]<0){
                ans = m-mid;
                e = mid-1;
                
                   

            }
            else{
                
                s = mid+1;
            }
          
           

        }
        // if(ans!=0){
        // ans = ans+1;
        // }
        cnt += ans;
    }

        return cnt;
        
    }
};
