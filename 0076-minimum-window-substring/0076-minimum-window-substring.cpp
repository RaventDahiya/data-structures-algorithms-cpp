class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        unordered_map<char, int> need;
        for (auto& ch : t) {
            need[ch]++;
        }
        int req = need.size();
        int formed = 0;
        unordered_map<char, int> window;
        int minLen = INT_MAX;
        int start = -1;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currCh = s[right];
            if (need.count(currCh)) {
                window[currCh]++;
                if (need[currCh] == window[currCh]) formed++;
            }

            while (formed == req) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                char prevCh = s[left];
                if (need.count(prevCh)) {
                    window[prevCh]--;
                    if (need[prevCh] > window[prevCh]) formed--;
                }
                left++;
            }
        }

        return start == -1 ? "" : s.substr(start, minLen);
    }
};