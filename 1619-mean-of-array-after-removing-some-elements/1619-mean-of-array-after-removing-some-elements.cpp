class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        double fi = 0.05*(arr.size());
        for(int i=0;i<fi;i++)
        {
            arr[i] = 0;
        }
       
        for(int i=arr.size()-1;i>=arr.size()-fi;i--)
        {
            arr[i] = 0;
        }
       
        double ans=0;
        
        for(int i=0;i<arr.size();i++)
        {
            ans = arr[i] + ans;
        }
        double rem = arr.size() - (2*fi);
        return (ans/rem);
       
    }
};
