class Solution {
private:
    const long long mod = 1e9+7;
public:
    int numTilings(int n) {
        vector<long long> t(1000, 0);
        t[1]=1;
        t[2]=2;
        t[3]=5;
        if(n<=3){
            return t[n];
        }
        for(int i=4;i<=n;i++){
            t[i]=2*t[i-1]+t[i-3];
            t[i]%=mod;
        }
        return t[n]%mod;
    }
};