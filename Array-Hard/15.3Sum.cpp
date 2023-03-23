class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n=nums.size();
        sort(nums.begin(),nums.end());
         vector<vector<int>>ans;
        for(int i=0;i<n-2;i++){
            int sum=0-nums[i];
             if(i==0 || i>0 && nums[i]!=nums[i-1]){
                 int s=i+1,e=n-1;
            while(s<e){
                int x=nums[s]+nums[e];

                if(x==sum){
                     vector<int>temp;
                     temp.push_back(nums[i]);
                      temp.push_back(nums[s]);
                       temp.push_back(nums[e]);
                       ans.push_back(temp);
                     

                     while(s<e &&nums[s]==nums[s+1])s++;
                     while(s<e &&nums[e]==nums[e-1])e--;
                     s++;
                     e--;

                }
                else if(x>sum){
                    e--;
                }
                else{
                    s++;
                }
            }
             }
        }
        return ans;
    }
};
