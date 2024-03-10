class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false; // Negative numbers and zero are not powers of two.
        }
        if (n == 1) {
            return true; // 2^0 = 1 is a power of two.
        }
        if (n % 2 != 0) {
            return false; // If n is not even, it's not a power of two.
        }
        return isPowerOfTwo(n / 2); // Recursively check the next value.
    }
};