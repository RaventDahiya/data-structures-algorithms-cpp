class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty()){
            auto frontPair = q.front(); q.pop();
            string frontString = frontPair.first;
            int frontDistance = frontPair.second;

            if(frontString==endWord) return frontDistance;

            for(int i=0;i<frontString.length();i++){
                char toChange = frontString[i];
                for(char ch='a' ; ch<='z' ; ch++){
                    frontString[i] = ch;
                    if(st.find(frontString)!=st.end()){
                        q.push({frontString,frontDistance+1});
                        st.erase(frontString);
                    }
                }

                frontString[i] = toChange;

            }
        }

        return 0;
    }
};