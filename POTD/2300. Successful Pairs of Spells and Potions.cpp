class Solution {
public:
int predicate(long long int s,long long int success){
    if(s>=success){
        return 1;

    }
    else{
        return 0;
    }

}
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
       
        sort(potions.begin(),potions.end());

        int n=spells.size();
        int m=potions.size();
      
         vector<int>ans;
        for(int i=0;i<n;i++)
        {   int x=0;
        int l=-1;
        int r=m;
        int mid;

        while(l+1<r){
            mid = l+(r-l)/2;
            long long int s=(long long)spells[i]*(long long)potions[mid];
            if(predicate(s,success)==1){
                r=mid;

            }
            else{
                l=mid;
            }
            


        }
           
            if(r==m || (((long long) spells[i]*(long long) potions[r])<success)){
                ans.push_back(0);
            }
            else{
                ans.push_back(m-r);
            }
        }
        return ans;
    }
};
