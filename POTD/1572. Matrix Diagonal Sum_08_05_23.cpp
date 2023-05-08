//Approach 1 O(N*M)

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      
        int sum=0;
        for(int i=0; i<mat.size(); i++)
        {
            for(int j=0; j<mat[i].size(); j++)
            {
                if(i==j || i+j==mat[i].size()-1)
                    sum+=mat[i][j];
            }
        }
        return sum;
      
    }
};

//Approach 2 O(N)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int sum = 0;

        for(int i =0; i<n ;i++){

        sum += mat[i][i] + mat[i][n-i-1];

        }

        if(n%2 == 1) sum -= mat[n/2][n/2];

        return sum;
        
    }
};

