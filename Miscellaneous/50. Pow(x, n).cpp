
//Approach 1(Using pow)

class Solution {
public:
    double myPow(double x, int n) {
        double ans=pow(x,n);
        return ans;
        
    }
};


//Approach 2(Using Recursion)

class Solution {
public:
    double myPow(double x, long long int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        if(n<0){
            n=-n;
            x=1/x;
        }
        if (n==1) return x;
        return (n%2==0) ? myPow(x*x,n/2):x*myPow(x*x,n/2);
    }
};
