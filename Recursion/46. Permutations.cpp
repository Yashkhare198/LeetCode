class Solution {
public:
void permute(vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,vector<bool>&freq)
{

    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i<nums.size() ; i++){
        if(!freq[i])
        {
            freq[i] = true;
            ds.push_back(nums[i]);
            permute(nums,ds,ans,freq);
            ds.pop_back();
            freq[i] = false;
        }
    }
}
    vector<vector<int>> permute(vector<int>& nums) {

        int n = nums.size();
       vector<vector<int>>ans;
       vector<int>ds;
      vector<bool>freq(n,false);
       permute(nums,ds,ans,freq);
       return ans;
    }
};
