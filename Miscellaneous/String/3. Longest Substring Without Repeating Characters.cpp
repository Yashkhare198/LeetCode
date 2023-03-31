//Approach 1

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

//Approach 2 (sliding window)

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.length();
        if(n==0) return 0;
      int maxi=INT_MIN;
          unordered_set<char>z;
          int left=0;
         
            
   
        for(int i=0;i<n;i++){

            if(z.count(s[i])==1){

                while(z.find(s[i])!=z.end()){
                    z.erase(s[left]);
                    left++;
                }
            }
            z.insert(s[i]);

        maxi=max(maxi,i-left+1);
        }
        return maxi;
        
     
    
        
    }
};
