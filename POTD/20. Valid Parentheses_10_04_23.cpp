class Solution {
public:

bool matching(char a,char b){
    if(a=='('  && b==')'|| a=='[' && b==']'||a=='{' && b=='}') return true;

    return false;
}

    bool isValid(string s) {
        stack<char>st;

        for(auto x:s){
            if(x=='('||x=='{'||x=='[')
            {
                st.push(x);
            }
            else{
                if(st.empty()) {
                    return false;
                }
                else if(matching(st.top(),x)==0)
                {
                    return false;
                }
                else{
                    st.pop();
                }
            }
        }
        return (st.empty()==true);
    }
};
