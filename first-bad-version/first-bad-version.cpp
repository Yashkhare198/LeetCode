// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int s = 0;
        int e = n;
        
        while(s+1<e)
        {
            int mid = s+(e-s)/2;
            
            if(isBadVersion(mid)==false)
            {
                s = mid;
            }
            else
            {
                e=mid;
            }
        }
        return e;
       
        
    }
};