class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
         long long int ans=nums[0],sum=0;

         for(int i=0;i<n;i++){

             sum += nums[i];
             long long int avg=ceil(sum*1.0/(i+1));

             ans = max(ans,avg);
         }


        return ans;
        
    }
};
