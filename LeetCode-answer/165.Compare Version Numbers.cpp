class Solution {
public:
    int compareVersion(string version1, string version2) {
        int pos1_h(0), pos1_t(0), pos2_h(0), pos2_t(0);
        string nStr1, nStr2;
        version1 = version1 + ".";
        version2 = version2 + ".";
        while ((pos1_t != -1) || (pos2_t != -1)) {
            int nData1(0), nData2(0);
            pos1_t = version1.find('.', pos1_h);
            pos2_t = version2.find('.', pos2_h);
            if (pos1_t != -1) {
                nStr1 = version1.substr(pos1_h, pos1_t - pos1_h);
                nData1 = stoi(nStr1);
                pos1_h = pos1_t + 1;
            }
            if (pos2_t != -1) {
                nStr2 = version2.substr(pos2_h, pos2_t - pos2_h);
                nData2 = stoi(nStr2);
                pos2_h = pos2_t + 1;
            }
            if (nData1 > nData2)
                return 1;
            else if (nData1 < nData2)
                return -1;
        }
        return 0;
    }
};
