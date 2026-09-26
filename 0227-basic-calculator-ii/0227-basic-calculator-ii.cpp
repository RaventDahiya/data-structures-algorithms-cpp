class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char op = '+';
        stack<int>st;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];

            if(isdigit(ch)) num = num*10 + (ch-'0');

            if((!isdigit(ch) && ch!=' ') || i==s.size()-1){
                if(op=='+') st.push(num);
                else if(op=='-') st.push(-num);
                else if(op=='*') {int top = st.top(); st.pop(); st.push(top*num);}
                else if(op=='/') {int top = st.top(); st.pop(); st.push(top/num);}

                op = ch;
                num = 0;
            }
        }

        int ans = 0;
        while(!st.empty()) {ans+=st.top(); st.pop();}
        return ans;
    }
};