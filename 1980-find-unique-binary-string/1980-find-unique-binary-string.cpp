class Solution {
public:
// Cantor diagonal argument
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size(); // all bitstrings are also same size;

        string out = string(len, '1');

        for  (int i = 0; i < len; i++) {
            out[i] = ('1' - nums[i][i]) + '0';
        }

        return out;
    }
};