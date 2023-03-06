class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                maxi=max(count,maxi);
                count=0;
            }
            else
            {
                count++;
            }
        }
        maxi=max(count,maxi);
        return maxi;
    }
};
