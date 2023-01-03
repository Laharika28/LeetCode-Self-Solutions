class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int l = strs[0].length();
        int cnt = 0;
        for (int j=0;j<l;j++) {
            char c = strs[0][j];
            for (int i=1;i<n;i++) {
                if ( c > strs[i][j] ) {
                    cnt++;
                    break;
                }
                c = strs[i][j];
            }
        }
        return cnt;
    }
};

// Davai