class Solution {
public:
    int calculate(string s) {
        long long num = 0;
        long long result = 0;
        long long sign = 1;

        stack<long long> st;

        for (char ch : s) {

            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            }

            else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            }

            else if (ch == '(') {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (ch == ')') {
                result += sign * num;
                num = 0;

                result *= st.top(); // sign before (
                st.pop();

                result += st.top(); // result before (
                st.pop();
            }
        }

        result += sign * num;

        return (int)result;
    }
};