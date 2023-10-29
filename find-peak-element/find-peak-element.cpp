class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (mid < right && nums[mid] < nums[mid + 1]) {
                // Move to the right subarray
                left = mid + 1;
            } else {
                // Move to the left subarray
                right = mid;
            }
        }
        
        // 'left' (or 'right') points to the peak element
        return left;
    }
};
