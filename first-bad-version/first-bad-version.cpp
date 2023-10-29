class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;

        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (isBadVersion(mid)) {
                // The current version is bad, so we move the search to the left.
                right = mid;
            } else {
                // The current version is not bad, so we move the search to the right.
                left = mid + 1;
            }
        }

        return left; // 'left' is the first bad version.
    }
};
