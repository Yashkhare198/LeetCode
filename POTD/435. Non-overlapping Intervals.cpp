class Solution {
public:
static bool comp(const vector<int> &a,const vector<int> &b) {
	return a[1]<b[1];
}
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size();

        if( n == 1) return 0;

        sort(intervals.begin(),intervals.end(),comp);

        int prevFirst = intervals[0][0];
        int prevSecond = intervals[0][1]; 
        int cnt = 0;

        for(int i = 1; i<n ; i++){

           

                if(prevSecond > intervals[i][0])
                {
                      cnt++;
                }
                else{
                      prevSecond = intervals[i][1];
                }

        }

        return cnt;
        
    }
};
