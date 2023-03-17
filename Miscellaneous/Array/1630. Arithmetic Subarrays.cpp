class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

vector<bool>ans(l.size(),false);
        int n=nums.size();
int x=0;
int sum=l.size();
        while(sum--){
                  bool flag=true;
            vector<int>temp;
for(int i=l[x];i<=r[x];i++){
    temp.push_back(nums[i]);
}
sort(temp.begin(),temp.end());

for(int j=0;j<temp.size()-1;j++)
{
    if(temp[j+1]-temp[j]!=temp[1]-temp[0]){
                    flag=false;
                    break;
                }
}
if(flag)
{
    ans[x]=true;
}
else
{
    ans[x]=false;
}
x++;
        }

        return ans;
    }
};
