class Solution {
public:
    int arraySign(vector<int>& nums) {
       long long  int prod = 1;

        for(int i = 0; i<nums.size() ;i++){
             if(nums[i] == 0) prod = 0 ;
           
           if(nums[i]<0){
               prod *= -1;
           }
           if(nums[i]>0){
               prod *= 1;
           }

        }

        if(prod < 0){
            return -1;
        }
        if(prod == 0){
            return 0;
        }

        return 1;
        
    }
};
