class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int res=0;
int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[res]=nums[i];
                res++;
            }

        }
        nums[res]=nums[n-1];
        res++;
        return res;
    }
};
