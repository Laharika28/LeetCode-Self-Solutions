class Solution {
public:
    int arrangeCoins(int n) {
        if (n==1) {
            return 1;
        }
        // long long int sum = 0;
        // for (int i=1;i<=n;i++) {
        //     sum += i;
        //     if (sum > n) {
        //         return i-1;
        //     }
        // }
        
        long long int x = 1;
        long long int count = 0;
        
        while (x<=n) {
            long long int y;
            y = x*(x+1)/2;
            if (y<=n) {
                count++;
            } 
            else {
                break;
            }
            x++;
        }
        
        return count;
    }
};