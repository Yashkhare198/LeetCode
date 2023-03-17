class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

     vector<int> trust_others(n+1), be_trusted(n+1);

        for(int i = 0; i < trust.size(); i++){
            trust_others[trust[i][0]]++;
            be_trusted[trust[i][1]]++;
        }

        for(int i = 1; i <= n; i++){
            if(trust_others[i] == 0 && be_trusted[i] == n-1){
                return i;
            }
        }

        return -1;
    }
};
