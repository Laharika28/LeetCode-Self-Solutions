class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int A1 = abs((ax2-ax1) * (ay2-ay1));
        int A2 =  abs((bx2-bx1) * (by2-by1));
        int x = min(bx2,ax2) - max(bx1,ax1);
        int y = min(by2,ay2) - max(by1,ay1);
        int A = 0;
        if(x>0 && y>0)
            A = x * y;
        return A1+A2-A;
    }
};