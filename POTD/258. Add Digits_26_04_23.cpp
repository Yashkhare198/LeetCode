#Approach 1(Brute Force)

class Solution {
public:
    int addDigits(int num) {
        int long  sum=0;
        int  a=0;
        while(num>9)
        {
            while(num>0)
            {
            a=num%10;
             sum+=a;
                num/=10;
            }
            num=sum;
            sum=0;
        }
        return num;
    }
};

#Approach 2(Digital Root O(1))
class Solution {
public:
    int addDigits(int num) {

        if(num == 0) return 0;

        return(num%9 == 0)?9:num%9;
    }
    
};
