class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        vector<int>str(26,-1);
        vector<int>end(26,0);
        for(int i=0;i<s.length();i++){
            int idx = s[i] - 'a';
            if(str[idx]==-1){
                str[idx] = i;
            }
            end[idx]=i;
        }
        vector<bool>isValid(26,true);
        for(int c=0;c<26;c++){
            if(str[c]==-1) continue;
            for(int i=str[c];i<=end[c];i++){
                if(str[s[i]-'a'] < str[c]){
                    isValid[c] = false;
                    break;
                }
                end[c] = max(end[c],end[s[i]-'a']);
            }
        }
        int lastTakenStart = INT_MAX;
        vector<string>result;
        for(int i=s.length()-1;i>=0;i--){
            int idx = s[i]-'a';
            if(!isValid[idx]) continue;
            if(i==str[idx] && end[idx]<lastTakenStart){
                result.push_back(s.substr(i,end[idx]-i+1));
                lastTakenStart = i;
            }
        }
        return result;
    }
};