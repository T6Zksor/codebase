class Solution {
public:
    int romanToInt(string s) {
       unordered_map<char, int> map = {
			{'I', 1},
			{'V', 5},
			{'X', 10},
			{'L', 50},
			{'C', 100},
			{'D', 500},
			{'M', 1000},
		};

		int outcome(map[s.back()]);

		for (uint ii = 0; ii < s.size() - 1; ++ii) {
			if (map[s[ii]] < map[s[ii + 1]]) {
				outcome -= map[s[ii]];
			}
			else {
				outcome += map[s[ii]];
			}
		}

		return outcome; 
    }
};
