//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
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

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends