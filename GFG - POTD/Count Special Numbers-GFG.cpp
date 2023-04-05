class Solution {
  public:
    int countSpecialNumbers(int N, vector<int> arr) {
      int n=arr.size();
      
     unordered_map<int, int> mp;
        for(int i=0;i<n;i++)
            mp[arr[i]]++;
            
        int special = 0;
        for(int i=0;i<n;i++) {
            int curr = arr[i];
            if(mp.count(curr)) {
                for(int j=0;j<n;j++) {
                    if(i != j and curr % arr[j] == 0) {
                        special += mp[curr];
                        mp.erase(curr);
                        break;
                    }
                }
            }
        }
        
        return special;
    }
};
