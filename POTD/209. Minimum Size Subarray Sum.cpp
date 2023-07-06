class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 0;
        int mini = INT_MAX;
        long long int sum = 0;

        while(i<n){

            sum += nums[i];

            while(sum-nums[j]>=target){
                sum = sum-nums[j];
                j++;
            }

            if(sum >= target){
                mini = min(mini,i-j+1);
            }
            i++;
        }

        if(mini == INT_MAX) return 0;
        return mini;
        
    }
};
