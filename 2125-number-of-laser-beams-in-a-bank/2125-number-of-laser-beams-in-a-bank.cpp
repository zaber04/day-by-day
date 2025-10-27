class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int previous = 0, ret = 0;
        
        for (string str : bank) {
            int count = 0;
            
            for (char ch : str) {
                if (ch == '1') {
                    count++;
                }
            }
            
            if (count != 0) {
                ret += (previous * count);
                previous = count;
            }
        }
        
        return ret;
    }
};