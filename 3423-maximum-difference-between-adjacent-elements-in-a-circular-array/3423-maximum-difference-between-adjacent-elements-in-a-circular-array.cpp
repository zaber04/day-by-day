class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int len = nums.size();
        int maxDiff = 0;

        for (int i = 1; i < len; i++) {
            maxDiff = max(abs(nums[i] - nums[i-1]), maxDiff);
        }

        maxDiff = max(abs(nums[0] - nums[len-1]), maxDiff);

        return maxDiff;
    }
};