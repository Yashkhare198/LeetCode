//User function Template for C++

class Solution{
public:
    int modulo(string s, int m){
        long long int ans = 0;
        long long int i = 1;
        for(int j = s.size() - 1; j >= 0; j--){
            ans += (s[j] - '0') * i;
            ans %= m;
            i = (i << 1) % m;
        }
        return ans;
    }
};

