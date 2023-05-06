class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
    int mod = 1e9 +7;
        int n = nums.size();
         int res = 0;

        sort(nums.begin(),nums.end());

        int s = 0;
        int e = n-1;
        vector<int>powerof2(n);
        powerof2[0] = 1;

        for(int i = 1; i<n ;i++){
            powerof2[i] = (powerof2[i-1] * 2)%mod;
        }

        while(s <= e){
           if(nums[s] + nums[e] <= target){
                   res = (res+powerof2[e-s])%mod;
                   
                   s++;
           }
           else if(nums[s] + nums[e] > target){
               e--;
           }
        }

       
        return res;
        
    }
};
