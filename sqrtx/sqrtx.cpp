class Solution {
public:
    int mySqrt(int x) {
        
        int s=0;
        int e=x;
        
        if(x==0)return 0;
        long long ans=0;
        while(s <= e){
            long long mid = s+(e-s)/2;
            
            if(mid*mid == x)
            {
                return floor(mid);
            }
            else if(mid*mid <x)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
        
    }
};