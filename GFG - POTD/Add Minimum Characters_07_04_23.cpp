class Solution{   
public:

bool palind(string s){
    int i=0;
    int j=s.size()-1;
    
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

    int addMinChar(string str){    
        //code here
        
        if(palind(str)) return 0;
        if(str.size()==1) return 0;
        
        for(int i=str.size()-1;i>0;i--){
            if(str[0]==str[i-1]&& palind(str.substr(0,i)))
            {
                return str.length()-i;
            }
        }
        return str.length()-1;
        
    }
};
