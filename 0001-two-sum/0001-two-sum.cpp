#define iPair pair<int, int>

class Solution {
    vector<int> firstApproach(vector<int>& nums, int target) {
        const int len = nums.size();

        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }

        return {};
    }

    vector<int> secondApproach(vector<int>& nums, int target) {
        // using hashtable, we reduce the second loop
        unordered_map<int, int> map;
        int len = nums.size();

        for (int i = 0; i < len; i++) {
            int complement = target - nums[i];

            // check if complement exists 
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }

            map[nums[i]] = i;
        }

        return {-1, -1};
    }

    vector<vector<int>> thirdApproach(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        int len = nums.size();
        vector<vector<int>> results;

        for (int i = 0; i < len; i++) {
            int complement = target - nums[i];

            // check if complement exists 
            if (map.find(complement) != map.end()) {
                results.push_back({map[complement], i});
            } else {
                map[nums[i]] = i;
            }
        }

        return results;
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // return firstApproach(nums, target);
        return secondApproach(nums, target);

        // vector<vector<int>> V = thirdApproach(nums, target);
        
        // return V[0];
    }
};