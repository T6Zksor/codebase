class Solution {
public:
    string longestPalindrome(string s) {
		bool dp[1000][1000] = {};
		int max_length(0), head(-1);
		for (int ii = s.length() - 1; ii >= 0 ; --ii) {
			for (int jj = ii; jj < s.length(); ++jj) {
				if (s[ii] == s[jj]) {
					if ((jj - ii <= 1) || (dp[ii + 1][jj - 1]))
						dp[ii][jj] = true;
				}
				if (dp[ii][jj] && jj - ii + 1 > max_length)
				{
					max_length = jj - ii + 1;
					head = ii;
				}
			}
		}
		return s.substr(head, max_length);
    }
};
