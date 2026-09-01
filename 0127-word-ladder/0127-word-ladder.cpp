class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue < pair<string, int>> q;
        q.push({beginWord, 1});
        st.erase(beginWord);
        while (!q.empty()) {
            auto [str,dist] = q.front(); q.pop();
            if(str==endWord) return dist;
            for (int i = 0; i < str.size(); i++) {
                char org = str[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch != org) {
                        str[i] = ch;
                        if (st.count(str)) {
                            q.push({str,dist+1});
                            st.erase(str);
                        }
                    }
                    str[i] = org;
                }
            }
        }
        return 0;
    }
};