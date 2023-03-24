class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
               
                int s=j+1;
                int e=n-1;
                 long long int x=(long long)target-(long long)nums[i]-(long long)nums[j];
                while(s<e){
                       long long   int sum=nums[s]+nums[e];
                    if(sum==x){
                           vector<int>temp;
                           temp.push_back(nums[i]);
                           temp.push_back(nums[j]);
                           temp.push_back(nums[s]);
                           temp.push_back(nums[e]);
                           ans.push_back(temp);

                           while(s<e &&nums[s]==temp[2])++s;
                           while(s<e &&nums[e]==nums[3])--e;
                           

                    }
                    else if(sum>x){
                        e--;
                    }
                    else{
                        s++;
                    }

                
                
            }
            while(j+1<n && nums[j]==nums[j+1])++j;
            }
          while (i + 1 < n && nums[i + 1] == nums[i]) ++i;
        }

return ans;

      
        
    }
};
