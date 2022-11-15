class Solution {
    
    int find_square(int n) {
        int ans = 0;
        while (n>0) {
            ans = ans + ((n%10)*(n%10));
            n = n/10;
        }
        return ans;
    }
    
public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        
        do {
            slow = find_square(slow);
            fast = find_square(find_square(fast));
        } while(slow!=fast);
        
        if (slow==1) {
           return 1; 
        }
        return 0;
    }
};