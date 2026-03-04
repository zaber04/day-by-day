class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rowLen = mat.size();
        int colLen = mat[0].size();

        vector<int> rowSums(rowLen, 0);
        vector<int> colSums(colLen, 0);

        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                if (mat[row][col] == 1) {
                    rowSums[row]++;
                    colSums[col]++;
                }
            }
        }

        int ret = 0;

        for (int row = 0; row < rowLen; row++) {
            for (int col = 0; col < colLen; col++) {
                if (mat[row][col] == 1) {
                    if (rowSums[row] == 1 && colSums[col] == 1) {
                        ret++;
                    }
                }
            }
        }

        return ret;
    }
};