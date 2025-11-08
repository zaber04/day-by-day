class Solution {
    int firstApproach(int n) {
        // unset msb
        // change i-th bit if (i-1)th bit is 1 and rest on right are 0 --> need 11

        // if n = 2^k then it will be 1 followed by k zeroes.
        // when n = 2^k --> we need 2^(k+1)-1 operations.
        // f(k) = f(k-1) + 1 + f(k-1) = 2 * f(k-1) + 1 = 2^(k+1) - 1

        if (n == 0) {
            return 0;
        }

        // find msb position
        int k = 0;
        int s = 1;

        while ((s << 1) <= n) {
            s <<= 1;
            k++;
        }

        return ((1 << (k+1)) - 1 - firstApproach(n ^ s));
    }

    int secondApproach(int n) {
        int ans = 0, k = 0, mask = 1;

        while (mask <= n) {
            if ((n & mask) != 0) {
                ans = (1 << (k+1)) - 1 - ans;
            }

            mask <<= 1;
            k++;
        }

        return ans;
    }
public:
    int minimumOneBitOperations(int n) {
        // return firstApproach(n);
        return secondApproach(n);
    }
};