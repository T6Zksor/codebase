class Solution {
public:
    int retMax(int a, int b) {
        return (a > b) ? a : b;
    }
    int retMin(int a, int b) {
        return (a < b) ? a : b;
    }

    int maxProduct(vector<int>& nums) {
        if (1 == nums.size())return nums[0];
        vector<int>::iterator itr(nums.begin());
        int Max(*itr), preMax(*itr), preMin(*itr);
        while (++itr != nums.end()) {
            int temp(preMax);
            preMax = retMax(retMax(*itr*preMax,*itr),*itr*preMin);
            preMin = retMin(retMin(*itr*temp,*itr),*itr*preMin);
            if (preMax > Max) Max = preMax;
        }
        return Max;
    }
};
