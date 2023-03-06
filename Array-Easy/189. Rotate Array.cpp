class Solution {
public:
void reverse(vector<int>&nums,int s,int e)
{
    while(s<e)
    {
        swap(nums[s++],nums[e--]);
    }

}
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n)
        {
            k=k%n;
        }
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-k-1);
        reverse(nums,0,n-1);
        

    }
};
