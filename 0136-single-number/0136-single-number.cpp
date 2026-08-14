class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            if (st.count(x))
                st.erase(x);
            else
                st.insert(x);
        }

        return *st.begin();
    }
};