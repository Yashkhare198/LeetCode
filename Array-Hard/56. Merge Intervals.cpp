class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> merge;
       if(intervals.size() == 0) return merge;

       sort(intervals.begin(),intervals.end());
       vector<int>temp = intervals[0];

       for(auto x: intervals){
           if(x[0] <= temp[1]){
               temp[1] =max(x[1],temp[1]);
           }
           else{
               merge.push_back(temp);
               temp=x;
           }
       }
       merge.push_back(temp);
       return merge;


        
    }
};
