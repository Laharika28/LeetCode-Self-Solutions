class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans(m);
        
        for(int k=0;k<m;k++){
            int i=0,j=k;
            bool flag=false;
            while(i<n && j<m){
                if (grid[i][j]==1) {
                    if (j==m-1) {
                        flag=true; break;
                    } else if(grid[i][j+1]==-1) {
                            flag=true; break;
                    }else {
                        i++; j++;
                    }
                } else {
                    if (j==0) {
                        flag=true; break;
                    } else if(grid[i][j-1]==1) {
                        flag=true; break;
                    }else {   
                        i++; j--;
                    }
                }
            }
            if (flag){
                ans[k] = -1;
            } else {
                ans[k] = j;
            }
        }
        return ans;
    }
};