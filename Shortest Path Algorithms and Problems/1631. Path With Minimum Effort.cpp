class Solution {
public:
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,1,0,-1};

bool bound(int i,int j,int n,int m){
    if(i>=0 && i<=n-1 && j>=0 && j<=m-1) return true;

    return false;
}

    int minimumEffortPath(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

            vector<vector<int>>dis(n,vector<int>(m,1e9));

            dis[0][0]=0;
            pq.push({0,{0,0}});

            while(!pq.empty()){
                auto node =pq.top();
                int diff= node.first;
                int r = node.second.first;
                int c = node.second.second;

                pq.pop();
                if(r==n-1 && c==m-1){
                    return diff;
                }

                for(int i=0;i<4;i++){
                    int nexti = dx[i] + r;
                    int nextj = dy[i] + c;

                    if(bound(nexti,nextj,n,m)){
                        int newEffort = max(abs(heights[nexti][nextj]-heights[r][c]),diff);
                        if(newEffort < dis[nexti][nextj]){
                            dis[nexti][nextj] = newEffort;
                            pq.push({dis[nexti][nextj],{nexti,nextj}});
                        }
                    }
                }

            }
            return 0;
        
    }
};
