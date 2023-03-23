// Approach1 (Using Hashmap)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n=nums.size();
        int z=n/3;
        unordered_map<int,int>mp;

        for(auto &x:nums){
            mp[x]++;
        }
        nums.clear();
        for(auto &x:mp){
            if(x.second>z){
                nums.push_back(x.first);
            }
        }
        return nums;
        
    }
};


//Approach 2(Using Moore's Voting Algorithm)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        int n=nums.size();
       int num1 =-1, num2 = -1,count1 = 0,count2 = 0;

       for(int i = 0;i < n; i++){
           if(nums[i] == num1){
               count1++;
           }else if(nums[i] == num2){
               count2++;
           }
           else if(count1 == 0){
               num1 =nums[i];
               count1 = 1;
           }
           else if(count2 == 0){
               num2 = nums[i];
               count2 = 1;
           }
           else{
               count1--;
               count2--;
           }
       }
        count1 = count2 =0;
        for(int i=0 ; i<n; i++){
            if(nums[i]==num1){
                count1++;
            }
            else if(nums[i]==num2){
                count2++;
            }
        }
        nums.clear();
        if(count1 >n/3){
            nums.push_back(num1);
        }
        if(count2 >n/3){
            nums.push_back(num2);
        }
        return nums;
    }
};

