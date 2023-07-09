class Solution {
public:

long long int robbed(vector<int>& nums) {

        long long int n = nums.size();

        if(n == 1) return nums[0];

        long long int prev = nums[0];
        long long int prev2 = 0;
        long long int curr = 0;

        for(int  i = 1; i<n ; i++){

            long long int take = nums[i];

            if(i>1)
            {
                take += prev2;
            }

            long long int notTake = 0 + prev;

            curr = max(take,notTake);

            prev2 = prev;
            prev = curr; 
        }

        return curr;
        
    }
    int rob(vector<int>& nums) {
         int n = nums.size();

    if(n ==  1) return nums[0];
    // if(n == 2) return max(nums[0],nums[1]);

    vector<int> temp1,temp2;

    for(int i = 0; i<n ; i++){

        if(i != 0) temp1.push_back(nums[i]);

        if(i != n-1) temp2.push_back(nums[i]);
    }

    long long int ans = max(robbed(temp1),robbed(temp2));

    return ans;
        
    }
};
