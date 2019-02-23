class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		int maxlength(0), head(-1);
		int map[256];
		memset(map, -1, sizeof(map));
		for (int i = 0; i < s.length(); ++i)
		{
			if (map[s[i]] > head)
				head = map[s[i]];
			map[s[i]] = i;
			maxlength = max(maxlength, i - head);
		}
		return maxlength;
    }
};
