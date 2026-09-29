class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;  
        int num = 0;
        string curr = "";
        for(auto &ch : s){
            if(isdigit(ch)){
                num = num * 10 + (ch-'0');
            }else if(ch=='['){
                countSt.push(num); num=0;
                strSt.push(curr); curr ="";
            }else if(ch==']'){
                int repeatCount = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();
                string temp = curr;
                for (int i = 0; i < repeatCount; i++) prev += temp;
                curr = prev;
            }else{
                curr += ch;
            }
        }
        return curr;
    }
};