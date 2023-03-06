class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
       int n=nums.size();

       
       vector<pair<int,int>>v;
       for(int i=0;i<n;i++)
       {
           v.push_back(make_pair(nums[i],i));
       }
       
       sort(v.begin(),v.end());
       int s=0;
       int e=n-1;
       while(s<e)
       {
           int x=v[s].first + v[e].first;
           if(x==target)
           {
               return {v[s].second,v[e].second};
           }
           else if(x<target)
           {
               s++;
           }
           else{
               e--;
           }
       }
       return {};
    }
};
