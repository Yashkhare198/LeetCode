class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       int n=nums.size();

       if(n==0 || n==1)
       {
           return n;
       }
set<int>s;
        for(auto &i:nums){
            
                s.insert(i);
        }
int count=0;
int num=*min_element(nums.begin(),nums.end());
int maxi=INT_MIN;
        for(auto x:s)
        {
            
            if(x!=num)
            {
               maxi=max(maxi,count);
               num=x;
               count=1;
               num++;
               continue;
            }
            num++;
            count++;
        }
        maxi=max(maxi,count);
        return maxi;
    }
};
