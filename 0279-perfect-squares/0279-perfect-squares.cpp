class Solution {
public:
    int numSquares(int n) {
        int c = floor(sqrt(n));
        vector<vector<int>> t(n+1,vector<int> (c+1,INT_MAX-1));
        
        for (int j=0;j<=c;j++) {
            t[0][j] = 0;
        }
        
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=c;j++) {
                if (i>=j*j) {
                    t[i][j] = min( 1+ t[i-(j*j)][j] , t[i][j-1] );
                } else {
                    t[i][j] = t[i][j-1];
                }
                // cout<<t[i][j]<<" ";
            }
            // cout<<endl;
        }
        // int mn = t[n][0];
        // for (int j=1;j<=c;j++) {
        //     mn = min (mn , t[n][j]);
        // }
        return t[n][c];
    }
};