class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>res;
        vector<int>pos;
        vector<int>neg;
        
        int n = nums.size()/2;

        for(auto i: nums)
        {
            if(i>0)
            {
                pos.push_back(i);
            }
            else
            {
                neg.push_back(i);
            }
        }
        for(int i=0;i<n;i++)
        {
            res.push_back(pos[i]);
            res.push_back(neg[i]);
        }
        return res;
    }
};
