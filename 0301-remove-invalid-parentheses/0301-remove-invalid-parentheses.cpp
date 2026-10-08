class Solution {
public:

    bool isValid(string& s) {
        int count = 0;

        for (char ch : s) {
            if (ch == '(') {
                count++;
            }
            else if (ch == ')') {
                count--;

                if (count < 0)
                    return false;
            }
        }

        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {

        queue<string> q;
        unordered_set<string> visited;
        vector<string> ans;

        q.push(s);
        visited.insert(s);

        bool found = false;

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                string curr = q.front();
                q.pop();

                if (isValid(curr)) {
                    ans.push_back(curr);
                    found = true;
                }

                // Don't generate next level
                // once valid strings are found
                if (found)
                    continue;

                for (int i = 0; i < curr.size(); i++) {

                    // Don't remove letters
                    if (curr[i] != '(' && curr[i] != ')')
                        continue;

                    string next =
                        curr.substr(0, i) +
                        curr.substr(i + 1);

                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }

            // This was the first valid level,
            // therefore minimum removals achieved.
            if (found)
                break;
        }

        return ans;
    }
};