class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int need = 0; // Number of ')' still required

        for (char ch : s) {
            if (ch == '(') {
                if (need % 2 == 1) {
                    insertions++; // Insert ')' to complete a pair
                    need--;
                }

                need += 2;
            } else {
                need--;

                if (need < 0) {
                    insertions++; // Insert '(' before this ')'
                    need = 1;     // Its second ')' is still needed
                }
            }
        }

        return insertions + need;
    }
};