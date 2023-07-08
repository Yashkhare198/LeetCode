
// 1st Approach

class Solution {
public:
   void subSets(int i,int n,vector<int>&nums,vector<vector<int>>&ans,vector<int>&subset,int sum,int target)
{
    if(sum==target)
    {
         ans.push_back(subset);
        return;

    }
    if(sum>target)
    {
        return;
    }
    if(i==n)
    {
        return;
       
    }
    else
    {
        subset.push_back(nums[i]);
        sum+=nums[i];
        subSets(i+1,n,nums,ans,subset,sum,target);
        subset.pop_back();
sum-=nums[i];

        while(i+1<n  && nums[i]==nums[i+1])i++;
       subSets(i+1,n,nums,ans,subset,sum,target);
    }
}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    int n=candidates.size();
    vector<int>subset;
    vector<vector<int>>ans;
    int sum=0;
    sort(candidates.begin(), candidates.end()) ;


    subSets(0,n,candidates,ans,subset,sum,target);
    return ans;

    }

};


// 2nd Approach

class Solution {
public:

    void findCombination(int ind, int target, vector<int>&arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if(target == 0)
        {
            ans.push_back(ds);
            return;

        }

        for(int i = ind; i<arr.size() ; i++){

            if(i>ind && arr[i] == arr[i-1]) continue;
            if(arr[i] > target) break;
            ds.push_back(arr[i]);
            findCombination(i+1,target - arr[i],arr, ans, ds);
            ds.pop_back();
        }
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        int n = candidates.size();
        
        vector<int>ds;

        vector<vector<int>>ans;

        sort(candidates.begin(),candidates.end());


        findCombination(0, target, candidates, ans, ds);

        return ans;


        
    }
};
