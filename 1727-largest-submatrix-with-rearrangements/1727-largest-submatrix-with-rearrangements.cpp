class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        // how much height each column contributes on its own.
        // modify matrix so that each matrix[row][col] represents the following value:
        // "how many consecutive 1s are there if we start from matrix[row][col] and move upward?"
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        vector<pair<int,int>> prevHeights;
        int ret = 0;

        for (int row = 0; row < rowLen; row++) {
            vector<pair<int,int>> heights;
            vector<bool> seen = vector(rowLen, false);

            for (int col = 0; col < colLen; col++) {
                if (matrix[row][col] && row > 0) {
                    matrix[row][col] += matrix[row-1][col];
                }
            }

            vector<int> curRow = matrix[row];
            sort(curRow.begin(), curRow.end(), greater());

            for (int col = 0; col < colLen; col++) {
                ret = max(ret, curRow[col] * (col + 1));
            }
        }

        return ret;
    }
};