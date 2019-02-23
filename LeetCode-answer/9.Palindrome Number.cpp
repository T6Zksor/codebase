class Solution {
public:
    bool isPalindrome(int x) {
        int reverse_x(0), copy_x(x);
		while (x > 0) {
			reverse_x = reverse_x * 10 + x % 10;
			x /= 10;
		}
		return reverse_x == copy_x;
    }
};
