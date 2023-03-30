class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if(n==0) return 0;
      int maxi=INT_MIN;
        for(int i = 0; i<n; i++){
            int j=i;
              unordered_set<char>z;
            while((j-i)==z.size() && j<n)
            {
                z.insert(s[j]);
                j++;
                int a=z.size();
                maxi=max(maxi,a);
            }


            
        }
        return maxi;
        
    }
};
