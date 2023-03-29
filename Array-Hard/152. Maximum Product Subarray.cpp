class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=nums[0];
        int mini=nums[0];
        int ans=nums[0];
         int n=nums.size();
       
       for(int i=1;i<n;i++)
       {
           if(nums[i]<0)
           {cout<<"H";
               swap(maxi,mini);
           }
      
           maxi=max(nums[i],maxi*nums[i]);
          cout<<maxi<<" ";
            mini=min(nums[i],mini*nums[i]);
            ans=max(ans,maxi);
           
       }
        return ans;
    }
};
