class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1==rec2) return true;

        int ax1 = rec1[0];
        int ay1 = rec1[1];
        int ax2 = rec1[2];
        int ay2 = rec1[3];

        int bx1 = rec2[0];
        int by1 = rec2[1];
        int bx2 = rec2[2];
        int by2 = rec2[3];

        if(ax2 <= bx1 || ay1 >= by2 || bx2<=ax1 || by1>= ay2) return false;
        return true;


    }
};