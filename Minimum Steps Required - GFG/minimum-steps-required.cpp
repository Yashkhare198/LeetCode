//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
     int c1=0;
    int max1=INT_MIN;
    int steps1=0;
    int steps2=0;
    int c2=0;
    int max2=INT_MIN;
    
    for(int i=0;i<str.length()-1;i++){
        
       if(i==0 &&str[i]=='a' || str[i]=='b' &&str[i+1]=='a'){
            steps1++;
        }
    }
    // if(c1!=0)steps1++;
    
    for(int j=0;j<str.length()-1;j++){
               
               if(j==0 &&str[j]=='b' || str[j]=='a' &&str[j+1]=='b'){
            steps2++;
        } 
        
    }    
        // if(c2!=0)steps2++;
        
        return min(steps1,steps2)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends