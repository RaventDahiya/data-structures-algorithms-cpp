class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size()>s.size()) return "";
        unordered_map<int,int>need;
        unordered_map<int,int>window;
        for(auto& ch:t){
            need[ch]++;
        }
        int req = need.size();
        int formed = 0;

        int minLen = INT_MAX;
        int start = -1;
        int left = 0;


        for(int right=0;right<s.length();right++){
            char currCh = s[right];
            if(need.count(currCh)){
                window[currCh]++;
                if(window[currCh] == need[currCh]) formed++;
            }

            while(req == formed){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    start = left;
                }
                char prevCh = s[left];
                if(need.count(prevCh)){
                    window[prevCh]--;
                    if(window[prevCh] < need[prevCh]) formed--;
                }
                left++;
            }
        }

        if(start==-1) return "";
        return s.substr(start,minLen);
    }
};