class Solution {
public:
    int search(vector<int>& nums, int target) {
        // n each iteration of binary search, we first check which half 
        // is sorted by comparing the left and middle elements. 
        // Then we check if the target is in that sorted half by comparing 
        // it with the left and middle elements. If it is in that sorted half, 
        // we search in that half as usual. If it is not in that sorted half, 
        // we search in the other half that contains the pivot.

        int low = 0;
        int high = nums.size() - 1;
        // bool isRotated = (nums[low] < nums[high]) ? false : true;

        while (low <= high) {
            int mid = (high + low) >> 1;

            if (nums[mid] == target) {
                return mid;
            }

            // look for sorted part respect to mid
            // check if target is in sorted part or the unsorted part
            if (nums[low] <= nums[mid]) {
                // lower part sorted
                if (nums[low] <= target && target <= nums[mid]) {
                    // target is in sorted part
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } else {
                // upper part sorted
                if (nums[mid] <= target && target <= nums[high]) {
                    // target is in sorted part
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};