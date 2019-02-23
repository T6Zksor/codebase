class Solution {
public:
    int reverse(int x) {
		int ret(0);
		while (x)
		{
			int t = ret * 10 + x % 10;
			if (t / 10 != ret) return 0;
			ret = t;
			x /= 10;
		}
		return ret;
    }
};
