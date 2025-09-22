class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int len = nums.size();

        unordered_map<int, int> hashmap;

        for (int num:nums) {
            hashmap[num]++;
        }

        int maxCount = 0;
        for (auto it : hashmap) {
            maxCount = max(maxCount, it.second);
        }

        int ret = 0;
        for (auto it : hashmap) {
            if (it.second == maxCount) {
                ret++;
            }
        }

        return ret * maxCount;
    }
};