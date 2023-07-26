
//Approach 1
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


//Approach 2

class Solution {
public:
void perm( vector<vector<int>>&ans,vector<int>& nums,int i)
{

    if(i >= nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for(int x = i; x<nums.size(); x++)
    {
        swap(nums[x],nums[i]);
        perm(ans,nums,i+1);
        swap(nums[x],nums[i]);

    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;

        perm(ans,nums,0);
        return ans;
        
    }
};
