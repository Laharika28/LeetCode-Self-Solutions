class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++){
           for(int j=i;j<m;j++){
               int t=matrix[i][j];
               matrix[i][j]=matrix[j][i];
               matrix[j][i]=t;
           }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m/2;j++){
                int t=matrix[i][j];
                matrix[i][j]=matrix[i][m-j-1];
                matrix[i][m-j-1]=t;
            }
        }
        
    }
};