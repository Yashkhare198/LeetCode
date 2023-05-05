class Solution {
public:
    string predictPartyVictory(string senate) {
        
        queue<int> qr,qd;
        int n = senate.size();
        for(int i = 0; i<n ;i++){
            if(senate[i] == 'R'){
                qr.push(i);
            }
            else{
                qd.push(i);
            }
        }

        while(!qr.empty() && !qd.empty()){
            int r_id =qr.front(),q_id =qd.front();
            qr.pop(); qd.pop();

            (r_id<q_id)?qr.push(r_id+n):qd.push(q_id+n);

        }
        return(qr.size()>qd.size())?"Radiant":"Dire";
    }
    
};
