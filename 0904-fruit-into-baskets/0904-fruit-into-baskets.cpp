class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ans = 0;
        int a,b,ain,bin,curr;
        curr = 0;
        int n = fruits.size();
        int i=0; 
        ain=0;
        a = fruits[0];
        while (i<n && fruits[ain] != a) {
            i++;
        }
        if (i==n) {
            return n;
        }
        bin = i;
        b = fruits[i];
        ans = b-a+1;
        curr = ans;
        int last_vis = b;
        i++;
        for (;i<n;i++) {
            if (fruits[i] == last_vis) {
                curr++;
            } else if (fruits[i] == a || fruits[i] == b) {
                curr++;
                if (fruits[i] == a) {
                    ain = i;
                    last_vis = a;
                } else {
                    bin = i;
                    last_vis = b;
                }
            } else {
                if (last_vis == a) {
                    b = fruits[i];
                    bin = i;
                    curr = bin-ain+1;
                    last_vis = b;
                } else {
                    a = fruits[i];
                    ain = i;
                    curr = ain-bin+1;
                    last_vis = a;
                }
            }
            ans = max(ans,curr);
        }
        return ans;
    }
};