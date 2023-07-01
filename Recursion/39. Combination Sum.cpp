class Solution {
public:

void helper(vector<int>& candidates, int target,int sum,int ind,int n,vector<int>&subset,vector<vector<int>>&ans)
{
   if(ind >=n ) return;

   if(sum>target) return;

  if(sum == target)
  {
      ans.push_back(subset);
      return;
  }

//NOT PICK
 helper(candidates,target,sum,ind+1,n,subset,ans);

 sum += candidates[ind];
  subset.push_back(candidates[ind]);

  //TO PICK
  helper(candidates,target,sum,ind,n,subset,ans);

  sum-= candidates[ind];
  subset.pop_back();

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int>>ans;

        vector<int>subset;
        int sum = 0;
        int ind = 0;

        int n = candidates.size();


         helper(candidates,target,sum,ind,n,subset,ans);

        return ans;
        
    }
};
