class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int j=0;j<m;j++){
            int r=1,c=j+1;
            int val = matrix[0][j];
            while(r<n && c<m){
                if(val != matrix[r][c]){
                    return false;
                }
                r++;c++;
            }
        }
        
        for(int i=1;i<n;i++){
            int r = i+1,c=1;
            int val = matrix[i][0];
            while(r<n && c<m){
                if(val != matrix[r][c]){
                    return false;
                }
                r++;c++;
            }
        }
        return true;
    }
};