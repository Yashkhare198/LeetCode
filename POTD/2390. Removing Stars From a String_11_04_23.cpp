class Solution {
public:
    string removeStars(string s) {
        int n=s.length();
       
        stack<char>st;
       for(int i=0;i<n;i++)
       {
          if(!st.empty()&&s[i]=='*'&&st.top()!='*'){
              st.pop();
              
          }
          else{
              st.push(s[i]);
          }
       }
        s.clear();
       while(!st.empty())
       {
           s.push_back(st.top());
           st.pop();
           
       }
       reverse(s.begin(),s.end());
        return s;
    }
};
