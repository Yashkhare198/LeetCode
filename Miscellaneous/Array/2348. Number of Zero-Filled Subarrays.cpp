class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long lastidx=-1,ans=0;
        for(int i=0;i<nums.size();i++){
            while(i<nums.size() && nums[i]==0){
                ans+=i-lastidx;
                i++;
            }
            lastidx=i;
        }
        return ans;
    }
};
