class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string>mp;
        for(auto &arr : knowledge){
            mp[arr[0]] = arr[1];
        }
        string result = "";

        int n = s.size();
        int i = 0;
        while(i<n){
            if(s[i]=='('){
                i++;
                string str = "";
                while(s[i]!=')') str += s[i++];
                i++;
                if(mp.count(str)) result += mp[str];
                else result += "?";
            }else{
                result += s[i++];
            }
        }
        return result;
    }
};