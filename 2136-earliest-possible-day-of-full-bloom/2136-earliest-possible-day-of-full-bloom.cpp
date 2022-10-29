class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>> seeds;
        for(int i=0;i<n;i++){
            seeds.push_back({growTime[i],plantTime[i]});
        }
        sort(seeds.begin(),seeds.end());
        int mxTime = seeds[n-1].first+seeds[n-1].second;
        int e = seeds[n-1].second;
        // cout<<mxTime<<" "<<e<<endl;
        for(int i=n-2;i>=0;i--){
            e = e + seeds[i].second;
            mxTime = max(mxTime,seeds[i].first+e);
            // cout<<mxTime<<" "<<e<<endl;
        }
        return mxTime;
    }
};