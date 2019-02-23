class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        vector<string>::iterator itr(strs.begin());
        string PreFix(*itr);

        while (++itr != strs.end()) {
            unsigned int i(0);
            while (i < (*itr).size() && i < PreFix.size()) {
                if ((*itr)[i] != PreFix[i])
                    break;
                i++;
            }
            PreFix = PreFix.substr(0, i);
        }
        return PreFix;

    }
};
