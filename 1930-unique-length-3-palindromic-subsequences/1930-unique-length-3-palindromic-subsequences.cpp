class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int len = s.size();

        vector<int> firstOccurance(26, -1);
        vector<int> lastOccurance(26, -1);

        // use bitmask
        // each loop bit 0-25 all set
        // increment counter if bit is set. reset bit in each iter --> each letter considered once
        // if bitmask is 0 --> all leters considered --> exit loop

        // find first & last occurance
        for (int i = 0; i < len; i++) {
            int position = int(s[i] - 'a');
            lastOccurance[position] = i;

            if (firstOccurance[position] == -1) {
                firstOccurance[position] = i;
            }
        }
        
        // the left, right character (first == last), middle is ignore
        int count = 0;

        for (int i = 0; i < 26; i++) {
            // character doesn't exist
            if (firstOccurance[i] == -1) {
                continue;
            }

            int startPos = firstOccurance[i];
            int lastPos  = lastOccurance[i];
            int bitMask  = (1 << 26) - 1; // 26 length '1's

            // search within start & end position
            for (int j = startPos + 1; (j < lastPos) && (bitMask > 0); j++) {
                // check if corresponding bit for s[j] is set or not
                int bitChecker = 1 << (s[j] - 'a');

                // will return true if bit is set
                if (bitMask & bitChecker) {
                    count++;
                }

                // reset the bit now --> since checked
                bitMask &= ~bitChecker;
            }
        }

        return count;
    }
};