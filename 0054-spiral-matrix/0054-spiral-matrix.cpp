class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int rstart = 0 , rend = n-1;
        int cstart = 0 , cend = m-1;
        
        vector<int> ans;

        while (rstart<=rend && cstart<=cend) {
            for (int j=cstart;j<=cend;j++) {
                ans.push_back( matrix[rstart][j] );
            }
            rstart++;
            if ( !(rstart<=rend && cstart<=cend) ) {
                break;
            }
            for (int i=rstart;i<=rend;i++) {
                ans.push_back( matrix[i][cend] );
            }
            cend--;
            if ( !(rstart<=rend && cstart<=cend) ) {
                break;
            }
            for (int j=cend;j>=cstart;j--) {
                ans.push_back( matrix[rend][j] );
            }
            rend--;
            if ( !(rstart<=rend && cstart<=cend) ) {
                break;
            }
            for (int i=rend;i>=rstart;i--) {
                ans.push_back( matrix[i][cstart] );
            }
            cstart++;
        }
        
        return ans;
    }
};