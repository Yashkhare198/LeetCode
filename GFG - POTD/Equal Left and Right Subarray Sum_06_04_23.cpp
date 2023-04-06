class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
     
     
     int total = 0;
     int suffix = 0;
     int prefix = 0;
     for(int i=0;i<N;i++){
         total += A[i];
     }
     suffix =total ;
     
     for(int j=0;j<N;j++){
       suffix -=A[j];
         if(prefix == suffix){
             return j+1;
         }
         prefix +=A[j];
         
     }
     return -1;
    }
};
