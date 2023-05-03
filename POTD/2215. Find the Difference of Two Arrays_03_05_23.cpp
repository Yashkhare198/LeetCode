class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        
      vector<int>v1,v2;
      map<int,int>m1,m2;
      int n = nums1.size();
      int m = nums2.size();
      for(int i=0;i<n;i++) m1[nums1[i]]++;

      for(int i=0;i<m;i++) m2[nums2[i]]++;


      for(int i = 0 ;i < n ;i++){
          if(m2[nums1[i]]==0){
              v1.push_back(nums1[i]);
              m2[nums1[i]]++;
          }
      }

      for(int j=0;j<m;j++){
          if(m1[nums2[j]]==0){
              v2.push_back(nums2[j]);
              m1[nums2[j]]++;
          }
      }

      vector<vector<int>>ans;
      ans.push_back(v1);
      ans.push_back(v2);
      return ans;
    }
};
