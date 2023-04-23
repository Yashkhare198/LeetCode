class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        // Code here
        int x=0;
        for(int i=0;i<n;i++){
            x=__gcd(arr[i],x);
        }
        return x;
    }
};
