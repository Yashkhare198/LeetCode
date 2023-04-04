int minSteps(string str) {
    // Write your code here.
    
    int steps1=0;
    int steps2=0;
   
    
    for(int i=0;i<str.length()-1;i++){
        
       if(i==0 &&str[i]=='a' || str[i]=='b' &&str[i+1]=='a'){
            steps1++;
        }
    }
   
    
    for(int j=0;j<str.length()-1;j++){
               
               if(j==0 &&str[j]=='b' || str[j]=='a' &&str[j+1]=='b'){
            steps2++;
        } 
        
    }    
        
        
        return min(steps1,steps2)+1;
}
