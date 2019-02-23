class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
			return nums.size();
		int dup = nums.size() -1;
		auto first = nums.begin() + 1;
		for (auto iter = nums.begin(); ++iter != nums.end();) {
			if (*iter != *(iter - 1)) {
				*first++ = move(*iter);
				--dup;
			}
		}
		return nums.size() - dup;
    }
};
