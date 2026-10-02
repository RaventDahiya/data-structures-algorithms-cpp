class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int ast : asteroids) {

            bool alive = true;

            while (alive &&
                   ast < 0 &&
                   !st.empty() &&
                   st.top() > 0) {

                int topAst = st.top();

                if (topAst < -ast) {
                    // stack asteroid destroyed
                    st.pop();
                }
                else if (topAst == -ast) {
                    // both destroyed
                    st.pop();
                    alive = false;
                }
                else {
                    // current asteroid destroyed
                    alive = false;
                }
            }

            if (alive) {
                st.push(ast);
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};