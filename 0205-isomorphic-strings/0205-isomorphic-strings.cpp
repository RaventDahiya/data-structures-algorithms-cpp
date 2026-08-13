class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> mpS(256, -1);
        vector<int> mpT(256, -1);

        for (int i = 0; i < s.size(); i++) {
            if (mpS[s[i]] != mpT[t[i]])
                return false;

            mpS[s[i]] = i;
            mpT[t[i]] = i;
        }

        return true;
    }
};