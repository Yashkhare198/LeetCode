class Solution {  
public:
    int minFlips(int a, int b, int c) {
        
        int x = a, y = b, z =c;
        int cnt = 0;
      
        int m =0;

        int last_x = a,last_y =b,last_z = c;
        while(x>0 || y>0 || z>0){
           
           last_x = x&1;
           last_y= y&1;
           last_z = z&1;

            if(last_z == 1 && (last_y == 0 && last_x ==0))
            {
                cnt++;
            }
            if(last_z ==0 &&  (last_x ==1 &&last_y==1 )){
                cnt += 2;
            }
             if(last_z ==0 &&  (last_x ==0 &&last_y==1 )){
                cnt++;
            }
             if(last_z ==0 &&  (last_x ==1 &&last_y==0 )){
                cnt++;
            }
            m++;
            x >>=1;
            y >>=1;
            z >>=1;
           

        }
        cout<<m;
        return cnt;
    }
};
