class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.length();
        if(n<=k) return s;
        
        int i = 0;
        string S = "";
        while(i<n){
            int sum = 0;
            for(int j=0;j<k && i<n;j++){
                sum += s[i]-'0';
                i++;
            }
            S += to_string(sum);
        }
        return digitSum(S,k);
    }
};