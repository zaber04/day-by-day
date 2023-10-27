#include <bits/stdc++.h>
using namespace std;

// Visit https://graphics.stanford.edu/~seander/bithacks.html

// Check if an integer is even or odd
bool isOdd(int num) {
	// 20 = 0001 0100
	// 11 = 0000 1011
	// 01 = 0000 0001

	return num & 1; // checking rightmost bit / least significant bit
}

// Detect if two integers have opposite signs or not
bool isOppositeSign(int x, int y) {
	// 4 in binary is  0000 0100
	// -8 in binary is 1111 1000

	// true if `x` and `y` have opposite signs
    return ((x ^ y) < 0);
}

bool isSameSign(int x, int y) {
	return ((x ^ y) >= 0);
}

// Add 1 to an integer
int incrementInt(int x) {
// The expression -~x will add 1 to an integer x. 
// We know that to get negative of a number, invert its bits and add 1 to it 
// (Remember negative numbers are stored in 2’s complement form)
// ~x is called 1's complement of x
// ~x = -(x+1) = -x-1
// hence, -~x = -(-(x+1)) = x+1
	return -~x;
}

int decrementInt(int x) {
	return -~x-2;
}

int invertInt(int x) {
	return ~x+1;
}

// x ^ x = 0
// x ^ 0 = x
// x ^ 1 = ~x

// Swap two numbers without using any third variable
// The idea is to use XOR operators to swap two numbers by their property x ^ x = 0

// called as intSwap(x, y)
void intSwap(int &x, int &y) {
	if (x != y) {
		x = x ^ y; // x now becomes x + y (binary digital sum / nim-sum / hardware sum)
		y = x ^ y; // here x^x comes into play, since x is now basically x+y, this is basically (x+y)^y which is simply x (y^y = 0 cancells y). now currently x holds  (x+y) and y hold original x
		x = x ^ y; // basically (x+y)^(x) since currently x holds  (x+y) and y hold original x
	}
}

// called as intSwap(&x, &y)
void intSwap2(int x, int y) {
	if (*x != *y) {
		*x = *x ^ *y;
		*y = *x ^ *y;
		*x = *x ^ *y;
	}
}

// Turn off n-th bit in a number
// & with 0 sets bit to 0
// & with 1 leaves bit as is

// 00010100    &                 (n = 20, k = 3)
// 11111011                    ~ (1 << (3-1))
// ~~~~~~~~
// 00010000
int unsetBit(int num, int position) {
	return (num & ~(1 << (position - 1)));
}

// Turn on k’th bit in a number
// | with 1 sets bit to 0
// | with 0 leaves bit as is

// 00010100    |               (n = 20, k = 4)
// 00001000                    (1 << (4 – 1))
// ~~~~~~~~
// 00011100

// position is 1 - 32 inclusive
int setBit(int num, int position) {
	return (num | (1 << (position - 1)));
}

// Check if k’th bit is set for a number
// & with 0 sets bit to 0
// & with 1 leaves bit as is

// 00010100    &               (n = 20, k = 3)
// 00000100                    (1 << (3-1))
// ~~~~~~~~
// 00000100                    non-zero value
int isBitSet(int num, int position) {
	return (num & (1 << (position - 1))) != 0; 
}

// Toggle the k’th bit
// x ^ x = 0
// x ^ 0 = x
// x ^ 1 = ~x // xor with 1 toggles the bit (1's complement)
int toggleBit(int num, int position) {
	return (num ^ (1 << (position - 1))); 
}

// unset the rightmost set bit of a number
// The expression n & (n-1) will turn off the rightmost set bit of a number n. The expression n-1 will have all the bits flipped after the rightmost set bit of n (including the rightmost set bit),  (2's complement). So, n & (n-1) will result in the last bit flipped of n.
int unsetRightmostBit(int num) {
	return num & (num-1); // note, num+1 = -~num

	// alternatively,
	// return num & ~(1);
}

// Check if a positive integer is a power of 2 without using any branching or loop
bool isPowerOfTwo(int num) {
	// power of 2 means number is in like 0010 0000 and hence n-1 is like 0001 1111
	// therefore n & (n-1) will be 0 and we return !0 (true)
	return !(num & (num-1)); 
} 

// If (n & -n) == n, then the positive integer n is a power of 2.
bool isPowerOfTwo2(int num) {
	// power of 2 means number is in like 0010 0000 and hence -n is like 1110 0000
	// therefore n & -n will be n
	return ((num & -num) == num); 
} 

// Find the position of the rightmost set bit
// The idea is to unset the rightmost bit of number n and XOR the result with n. 
// Then the rightmost set bit in n will be the position of the only set bit in the result (it will be a power of 2). Then we can do rightshifting untill we get the set bi position.
// Note that if n is odd, we can directly return 1 as the first bit (rightmost bit) is always set for odd numbers.

// 00010100    &                (n = 20)
// 00010011                     (n-1 = 19)
// ~~~~~~~~
// 00010000    ^                (XOR result number with n)
// 00010100
// ~~~~~~~~
// 00000100  ——  rightmost set bit will tell us the position
int rightmostSetBitPosition(int num) {
	// is odd?
	if (num & 1) {
		return 1;
	}

	// unset rightmost set bit and xor with original
	int result = num ^ (num & (num-1));

	// find the position of the only set bit in the result;
    // we can directly return `log2(result) + 1` from the function
    int pos = 0;

    while (result)  {
        result = result >> 1;
        pos++;
    }

    return pos;
}

// reuslt = n & -n. Here the position of the rightmost set bit in n will be the position of the only set bit in the result. 
// If (n & -n) == n, then the positive integer n is a power of 2.
int rightmostSetBitPosition(int num) {
	// is odd?
	if (num & 1) {
		return 1;
	}

	// unset rightmost set bit and xor with original
	int result = num ^ -num;

	// find the position of the only set bit in the result;
    // we can directly return `log2(result) + 1` from the function
    int pos = 0;

    while (result)  {
        result = result >> 1;
        pos++;
    }

    return pos;
}

// Find the position of the only set bit in a number
int onlySetBitPosition(int num) {
	// this means, it's a power of 2
    return log2(num) + 1;
}

// Computing parity of a number
// “Parity” refers to the total number of 1s in a binary number. 
// The odd parity(1) means an odd number of 1s, and even parity(0) means an even number of 1s. 
// Parity bits are often used as a simple means of error detection as digital data is transmitted and received.

// We can turn off the rightmost set bit of the number one by one and count the parity. The following code uses an approach like Brian Kernighan’s (https://www.techiedelight.com/brian-kernighans-algorithm-count-set-bits-integer/) bit counting. The time it takes is proportional to the total number of bits set.
bool isOddParity(int num) {
	bool parity = false;

	// run until num becomes 0
	while (num) {
		// invert the parity flag
        parity = !parity;
		num = num & (num-1); // turn off rightmost set bit
	}

	return parity;
}

// odd parity or even parity?
// Brian Kernighan method
int countSetBits(int num) {
	int counter = 0;

	// run until num becomes 0
	// loop runs as many times as there is set bit
	while (num) {
		num = num & (num-1); // turn off rightmost set bit
		counter++;
	}

	return counter;
}

// brute force
int countSetBits2(int num) {
	int counter = 0;

	// run until num becomes 0
	while (num) {
		if (num & 1) {
			counter++;
		}

		num >>= 1;
	}

	return counter;
}

// Using GCC built-in function
int countSetBits3(unsigned int num) {
	// int __builtin_popcount (unsigned int n)
	// int __builtin_popcountl (unsigned long)
	// int __builtin_popcountll (unsigned long long)

	return  __builtin_popcount (num);
}

// Using std::bitset::count function
int countSetBits4(unsigned int num) {
	bitset<32> bs(num);

	return  bs.count();
}

// Divide and Conquer
// The idea is to calculate the parity of an integer by recursively dividing the 32–bit integer 
// into two halves and take their XOR until only the 1 bit is left. 
// Taking the XOR will cancel out set bits at the same position in two halves, 
// and since parity will not be affected if we take out even set bits from it, 
// the problem is successfully reduced to half at each step.
bool isOddParity2(int num) {
	// recursively divide the (32–bit) integer into two equal
    // halves and take their XOR until only 1 bit is left

    x = (x & 0x0000FFFF) ^ (x >> 16); // first bracket returns lower half of x and second half returns upper half and hence we XOR upper with lower
    x = (x & 0x000000FF) ^ (x >> 8);
    x = (x & 0x0000000F) ^ (x >> 4);
    x = (x & 0x00000003) ^ (x >> 2);
    x = (x & 0x00000001) ^ (x >> 1);
 
    // return 1 if the last bit is set; otherwise, return 0
    return x & 1;
}

bool isOddParity3(int num) {
	// recursively divide the (32–bit) integer into two equal
    // halves and take their XOR until only 1 bit is left
 
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
 
    // return 1 if the last bit is set; otherwise, return 0
    return x & 1;
}

// Using a Lookup Table

// We create an 8–bit (1 byte) lookup table, 
// then iterate over each byte in the integer to be checked and summing the table lookup results.
// 1 byte with all its bits set is 255 in decimal (11111111 in binary), 
// and all bits unset is 0 in decimal (00000000 in binary). 
// So, the lookup table should be of size 256 (0-255).

// Macros to generate the lookup table (at compile-time)
#define P2(n) n, n^1, n^1, n
#define P4(n) P2(n), P2(n^1), P2(n^1), P2(n)
#define P6(n) P4(n), P4(n^1), P4(n^1), P4(n)
#define FIND_PARITY P6(0), P6(1), P6(1), P6(0)

bool isOddParity4(int num) {
	unsigned int lookup[256] = { FIND_PARITY };

    // Assuming 32–bit (4 bytes) integer, break the integer into
    // 16–bit chunks and take their XOR
    x ^= x >> 16;
 
    // Again split the 16–bit chunk into 8–bit chunks and take their XOR
    x ^= x >> 8;
 
    // Note mask used 0xFF is 11111111 in binary
    return lookup[x & 0xFF];
}

// Convert uppercase character to lowercase
// We can easily convert an uppercase character to a corresponding lowercase character 
// by taking its bitwise OR with a space.

// ‘A’ — 01000001 ‘a’ — 01100001
// ‘B’ — 01000010 ‘b’ — 01100010
// ‘C’ — 01000011 ‘c’ — 01100011
// ‘D’ — 01000100 ‘d’ — 01100100
// ‘E’ — 01000101 ‘e’ — 01100101

// We notice that the ASCII codes of lowercase and uppercase characters differ only in their third significant bit. 
// For uppercase characters, the bit is 0, and for lowercase characters, the bit is 1. 
// If we could find a way to set/unset that particular bit, we can easily invert any character’s case. Now space ' ' has an ASCII code of 00100000 and '_' has an ASCII code of 01011111.

char toUpperCase(char ch) {
	return char(ch | ' ');        // prints  any of abcdefghijklmnopqrstuvwxyz
}

// Convert lowercase character to uppercase
char toLowerCase(char ch) {
	return char(ch & '_');
}

// Invert alphabet’s case
char toggleCase(char ch) {
	return char(ch ^ ' ');
}

//  Find a letter’s position in alphabet
// We can easily find a letter’s position [1-26] in the alphabet by taking its bitwise AND with ASCII 31 (00011111 in binary).  The case of the letter is irrelevant here.
// (‘A’ & 31) returns position 1
// (‘c’ & 31) returns position 3
// AND by chr(31)/binary('11111')/(hex('1F') => (x & "\x1F")

// Get letter's position in alphabet (for Uppercase letters only):
// AND by ? => (x & '?') or XOR by @ => (x ^ '@')
// eg. ('C' & '?') => 3 ; ('Z' ^ '@') => 26
// Get letter's position in alphabet (for lowercase letters only):

// XOR by backtick/chr(96)/binary('1100000')/hex('60') => (x ^ '`')
// eg. ('d' ^ '`') => 4 ; ('x' ^ '`') => 25
// Note: using anything other than the english letters will produce garbage results
int alphabetPosition(char s) {
	return (s & 31);
}

// Get the maximum integer
int maxInt() {
	int maxInt  = ~(1 << 31);
	int maxInt1 = (1 << 31) - 1;
	int maxInt2 = (1 << -1) - 1;

	return maxInt;
}

// Get the minimum integer
int minInt() {
	int minInt  = 1 << 31;
	int minInt1 = 1 << -1;

	return minInt;
}

// Get the maximum long
int getMaxLong() {
	long maxLong = ((long)1 << 127) - 1;

	return maxLong;
}

// Get absolute value
// get msb by n >> 31
// xor the number with msb (returns 0 or 1)
// now subtract the number

// alternatively  (num + mask ) ^ (mask) works too where mask = num >> 31
// n ^ 0 = n
// -n = ~n + 1
// n = ~(-n – 1)
// The mask n >> 31 is evaluated to 0 (zero) for positive numbers and -1 (non-zero) for negative numbers. 
// Similarly, the mask ~n >> 31 is evaluated to 0 (zero) for negative numbers and -1 (non-zero) for positive numbers.

// remember - num ^ 0 = num, num ^ 1 = ~num
// 00000110                        (n = 6)
// 00000000                        (mask = 0)
// 00000110    ^                   (n + mask)
// 00000000                        (mask)
// ~~~~~~~~
// 00000110                        abs(n)
 

// 11111010                        (n = -6)
// 11111111                        (mask = -1)

// 11111001    ^                   (n + mask)
// 11111111                        (mask)
// ~~~~~~~~
// 00000110                        abs(n)
int getAbs(int num) {
	return (num + (num >> 31)) ^ (num >> 31);
	// return (num ^ (num >> 31)) - (num >> 31);
	// return ((n >> 31) & (~n + 1)) | ((~n >> 31) & n);
}

// Modulo 2^n against m
// return m & (n - 1);

// Finding the most significant set bit (MSB) / leftmost set bit
int leftmostSetBit(int n) {
    // n |= (n >>  1);
    // n |= (n >>  2);
    // n |= (n >>  4);
    // n |= (n >>  8);
    // n |= (n >> 16);
    // return n - (n >> 1);

	// Below steps set bits after
    // MSB (including MSB)
 
    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;
 
    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
 
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
 
    // Increment n by 1 so that
    // there is only one set bit
    // which is just before original
    // MSB. n now becomes 1000000000
    n = n + 1;
 
    // Return original MSB after shifting.
    // n now becomes 100000000
    return (n >> 1);
}

// Clear all bits from LSB to ith bit 
int clearIBitsFromLsb(int num, int i) {
	int mask = ~((1 << i+1 ) - 1);
	return num & mask;
}

// Clearing all bits from MSB to i-th bit
int clearIBitsFromMsb(int num, int i) {
	int mask = (1 << i) - 1;
	return num & mask;
}