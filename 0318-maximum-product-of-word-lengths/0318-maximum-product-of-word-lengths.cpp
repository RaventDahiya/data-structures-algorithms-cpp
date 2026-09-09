class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi = 0;
        int n = words.size();

        for(int i=0;i<n-1;i++){
            string str1 = words[i];
            unordered_set<char>st;
    
            for(auto ch : str1){
                st.insert(ch);
            }
            int len1 = str1.length();
            bool commonLetter = false;
            for(int j=i+1;j<n;j++){
                string str2 = words[j];
                for(auto ch : str2){
                    if(st.count(ch)){ //common letter found
                        commonLetter = true;
                        break;
                    }
                }
                if(!commonLetter){
                    
                    int len2 = str2.length();
                    maxi = max(maxi,len1*len2);
                }
                commonLetter = false;
            }
        }
        return maxi;
    }
};