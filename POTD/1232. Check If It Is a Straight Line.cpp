class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        float ans = 0;

       int x1 = coordinates[0][0];
       int y1 = coordinates[0][1];

       int x2 = coordinates[1][0];
       int y2 = coordinates[1][1];

       if(x1 == 0   && x2 ==0){

           for(int i=2; i<n ;i++){
               if((coordinates[i][0]!=0) || (coordinates[i-1][0]!=0)){
                   return false;
               }
           }
           return true;
       }

        ans = float(y2-y1)/(x2-x1);

       for(int i = 2; i<n ; i++){
           
           float m = float(coordinates[i][1]-coordinates[i-1][1])/(coordinates[i][0]-coordinates[i-1][0]);

           if(m!=ans){
               return false;
           }

           
       }

       return true;
    
        
    }
};
