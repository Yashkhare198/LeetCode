class Solution {
  public:
    int bitMagic(int n, vector<int> &arr) {
        // code here
        
        
        int s = 0;
        int e = n-1;
        
        int count = 0;
        
        while(s<=e){
            
            if(arr[s] != arr[e]){
                count++;
            }
            s++;
            e--;
            
        }
        
       return (count%2 ==0)? count/2: count/2 + 1;
    }
};
