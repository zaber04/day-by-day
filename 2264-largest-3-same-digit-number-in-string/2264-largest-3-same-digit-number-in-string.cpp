class Solution {
    // manually check
    bool matchFound(string needle, string haystack, int len) {
        for (int i = 0; i <= len - 3; ++i) {
            if (haystack[i] == needle[0] &&
                haystack[i+1] == needle[1] &&
                haystack[i+2] == needle[2]
            ) {
                return true;
            }
        }

        return false;
    }

    string firstApproach(string num) {
        int len = num.size();

        // can we check 999, 888, ..., 000 manually?
        string checkers[] = { "999", "888", "777", "666", "555", "444", "333", "222", "111", "000" };

        for (int i = 0; i < 10; i++) {
            if (matchFound(checkers[i], num, len)) {
                return checkers[i];
            }
        }

        return "";
    }

    // sliding window --> helps for large number or different base
    string secondApproach(string num) {
        // we maintain a window of size 3 
        // if all chars are same --> we store that (max value)
        char maxDigit = '\0';
        int len = num.size();
    
        #pragma unroll
        for (int i = 0; i <= len - 3; i++) {
            if (num[i] == num[i+1] && num[i] == num[i+2]) {
                maxDigit = max(maxDigit, num[i]);
            }
        }

        return ((maxDigit == '\0') ? "" : string(3, maxDigit));
    }
public:
    string largestGoodInteger(string num) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        return firstApproach(num);
        return secondApproach(num);
    }
};