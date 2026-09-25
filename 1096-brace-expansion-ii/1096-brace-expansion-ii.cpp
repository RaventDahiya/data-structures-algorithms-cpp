class Solution {
public:
    // Cartesian product:
    // {"a","b"} x {"c","d"}
    // -> {"ac","ad","bc","bd"}
    set<string> combine(set<string>& a, set<string>& b) {
        set<string> res;

        for (auto &x : a) {
            for (auto &y : b) {
                res.insert(x + y);
            }
        }

        return res;
    }

    set<string> solve(string& s, int& i) {

        // Stores union result
        set<string> total;

        // Stores current concatenation group
        set<string> curr = {""};

        while (i < s.size() && s[i] != '}') {

            // -------------------------
            // CASE 1: letter
            // -------------------------
            if (isalpha(s[i])) {

                set<string> temp;
                temp.insert(string(1, s[i]));

                curr = combine(curr, temp);
                i++;
            }

            // -------------------------
            // CASE 2: nested {...}
            // -------------------------
            else if (s[i] == '{') {

                i++; // skip {

                set<string> inside = solve(s, i);

                i++; // skip }

                curr = combine(curr, inside);
            }

            // -------------------------
            // CASE 3: comma = UNION
            // -------------------------
            else if (s[i] == ',') {

                // Add current expression to total
                total.insert(curr.begin(), curr.end());

                // Start new expression
                curr = {""};

                i++;
            }
        }

        // Add final expression
        total.insert(curr.begin(), curr.end());

        return total;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> ans = solve(expression, i);

        return vector<string>(ans.begin(), ans.end());
    }
};