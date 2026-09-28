class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int maxi = 0;
        for(auto &ch : s){
            if(ch=='('){
                open++;
                maxi = max(maxi,open);
            }else if(ch==')'){
                open--;
            }
        }
        return maxi;
    }
};