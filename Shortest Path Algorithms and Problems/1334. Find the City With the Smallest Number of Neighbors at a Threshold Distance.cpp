class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>>dis(n,vector<int>(n, INT_MAX));

        for(auto x :  edges){
            dis[x[0]][x[1]] = x[2];
            dis[x[1]][x[0]] = x[2];
        }

        for(int  i =0 ;i<n ;i++) dis[i][i] = 0;

        for(int k = 0; k<n ; k++){
            for(int i = 0;  i<n ; i++){
                for(int j = 0; j<n ; j++){
                    if(dis[i][k] == INT_MAX || dis[k][j] == INT_MAX){
                        continue;
                    }
                    dis[i][j] = min(dis[i][j] , dis[i][k]+dis[k][j]);
                }
            }
        }
        int cntCity = n;
        int cityNo = -1;

        for(int city = 0; city<n ; city++){
            int cnt = 0;
            for(int adjCity = 0; adjCity <n; adjCity++){
                if(dis[city][adjCity] <= distanceThreshold) cnt++;
            }
            if(cnt <= cntCity){
                cntCity = cnt;
                cityNo = city;
            }
        }
        return cityNo;
    }
};
