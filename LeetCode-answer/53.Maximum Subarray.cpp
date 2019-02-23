class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int>::iterator itr(nums.begin());
        int Max(*itr), preMax(*itr);
        while (++itr != nums.end()) {
            if (*itr + preMax < *itr) preMax = *itr;
            else preMax += *itr;
            if (preMax > Max) Max = preMax;
        }
        return Max;
    }
};
