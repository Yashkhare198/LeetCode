class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int zeros = 0;
        int ones = 0;
        int maxi = 0;

        while (j < n) {
            if (nums[j] == 0) {
                zeros++;
            }

            while (zeros > 1) {
                if (nums[i] == 0) {
                    zeros--;
                }
                i++;
            }
            int len;
            if(zeros == 0)
            {
                    len = j - i +1;
            }
            else{
             len = j - i ;
            }
            maxi = max(maxi, len);

            if (zeros <= 1) {
                j++;
            }
        }

        if (maxi == n)return maxi-1;

        return maxi;
    }
};
