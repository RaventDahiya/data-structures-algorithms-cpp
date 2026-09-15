class Solution {
public:
    int reverseBits(int n) {
        int R = 0;
        for(int i=0;i<32;i++){
            R<<=1;
            R|= (n&1);
            n >>=1;
        }
        return R;
    }
};