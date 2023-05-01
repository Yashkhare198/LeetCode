// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        
        
        int cnt=0;
        
        queue<int>q;
        vector<int>dis(1e5,1e9);
        dis[start]=0;
        q.push(start);
        int mod = int(1e5);
        bool x =false;
        while(!q.empty()){
            
            int node = q.front();
            q.pop();
          
            for(int i=0;i<arr.size();i++){
                int mpy = arr[i]*node;
                mpy =mpy%mod;
               
                if(mpy == end){
                   return dis[node]+1;
                }
                if(dis[node]+1<dis[mpy]){
                    q.push(mpy);
                    dis[mpy]=1+dis[node];
                }
            }
        }  
        return -1;
    }
};
