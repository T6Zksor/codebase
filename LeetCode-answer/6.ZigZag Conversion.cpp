class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows <= 1)
            return s;

        vector<string> vsData(numRows);

        int nRowNow(0), nStep(1);
        for (auto ch : s)
        {
            vsData[nRowNow].push_back(ch);
            nRowNow += nStep;
            if (nRowNow == 0 || nRowNow == numRows - 1)
                nStep *= -1;
        }

        string strRet;

        for (auto ss : vsData)
        {
            strRet.append(ss);
        }

        return strRet;
    }
};
