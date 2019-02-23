class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        unordered_map<int, int> u_map;

        for (int ii = 0; ii < nums.size(); ++ii)
        {
            int nTar = target - nums.at(ii);
            if (u_map.find(nTar) != u_map.end())
            {
                ret.empty();
                ret.push_back(u_map.at(nTar));
                ret.push_back(ii);
                break;
            }
            else
                u_map[nums.at(ii)] = ii;

        }
        return ret;
    }
};
