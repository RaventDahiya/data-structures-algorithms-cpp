class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,1});

        while(!q.empty()){
            auto [str,dis] = q.front(); q.pop();
            if(str==endWord) return dis;
            
            for(int i=0;i<str.length();i++){
                char org = str[i];
                for(char ch='a';ch<='z';ch++){
                    str[i] = ch;
                    if(st.count(str)){
                        q.push({str,dis+1});
                        st.erase(str);
                    }
                }
                str[i] = org;
            }
            
        }

        return 0;
    }
};