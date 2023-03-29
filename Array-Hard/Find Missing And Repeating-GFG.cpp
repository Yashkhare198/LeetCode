//Approach 1  (T.C- O(n) & S.C -O(n)

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
     
      int a[n+1]={0};
        
     
        for(int i=0;i<n;i++)
        {
            a[arr[i]]++;
        }
        int r=0;
        int m=0;
        
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                m=i;
            }
            if(a[i]>1)
            {
                
                r=i;
            }
           
        }
     int *x= new int[2];
     x[0]=r;
     x[1]=m;
     
     return x;
    }
};

//Approach-2 (Using XOR)  T.C- O(n) & S.C -O(1)

 for(int i=0;i<n;i++)
       {
           if(arr[i]&s)
           {
               x=x^arr[i];
           }
           else{
               y=y^arr[i];
           }
       }
