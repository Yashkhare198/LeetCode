class Solution {
public:
    double average(vector<int>& salary) {
        int maxi = *max_element(salary.begin(),salary.end());
        int mini = *min_element(salary.begin(),salary.end());
           double sum =0;
           int cnt = 0;
        for(int i = 0 ; i<salary.size() ;i++){

            if(salary[i] != maxi && salary[i] != mini){
                   sum += salary[i];
                   cnt ++;
            }
        }
        return sum/cnt;
    }
};
