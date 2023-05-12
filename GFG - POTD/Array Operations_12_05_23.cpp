class Solution {
  public:
    int arrayOperations(int n, vector<int> &arr) {
        // code here
        int count =0;
        int nonZero;
        for(int i = 0; i<n; i++){
            
            if(arr[i]==0){
                if(nonZero){
                    count++;
                    nonZero=0;
                }
            }
                else{
                    nonZero++;
                }
            
            
        }
        if(nonZero == n){
            return -1;
        }
        else if(nonZero){
            count++;
        }
         return count;
        
    }
};
