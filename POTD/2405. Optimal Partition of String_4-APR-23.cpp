class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> z;
        int partition=1;

        for(int i=0;i<s.length();i++){
             if(z.find(s[i])!=z.end()){

                partition++;
                z.clear();
                z.insert(s[i]);
            }
            else{
                z.insert(s[i]);
            }
        }
        return partition;
    }
};
