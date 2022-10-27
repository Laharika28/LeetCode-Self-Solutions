class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int,int>> coord1,coord2;
        int n=img1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1){
                    coord1.push_back({i,j});
                }
                if(img2[i][j]==1){
                    coord2.push_back({i,j});
                }
            }
        }
        
        map<pair<int,int>,int> mp;
        int ans=0;
        for(int x=0;x<coord1.size();x++){
            for(int y=0;y<coord2.size();y++){
                int i1=coord1[x].first,j1=coord1[x].second;
                int i2=coord2[y].first,j2=coord2[y].second;
                mp[{i2-i1,j2-j1}]++;
                ans=max(ans,mp[{i2-i1,j2-j1}]);
            }
        }
        return ans;
    }
};