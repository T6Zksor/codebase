class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        nums.erase(remove_if(nums.begin(), nums.end(),
			[&val](int ele) { return ele == val; }),
			nums.end());
		return nums.size();
    }
};
