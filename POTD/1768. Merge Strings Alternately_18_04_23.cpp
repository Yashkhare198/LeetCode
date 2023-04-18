class Solution {
public:
    string mergeAlternately(string word1, string word2) {

        int n = word1.length();

        int m = word2.length();
        
        string ans;

        int i = 0, j = 0;
           int k = 0;
        while(i < n || j< m){

            if(i<n){
                ans.push_back(word1[i]);
                i++;
            }
           if(j<m){
                   ans.push_back(word2[j]);
                j++;
            }
            

        }

    

        return ans;
    }
};
