class Solution {
    int solve(vector<int>& cost,int i,int n,vector<int>& t) {
        if(i>=n) {
            return 0;
        }
        if(t[i] != -1) {
            return t[i];
        }

        return t[i] = cost[i] + min(solve(cost,i+1,n,t) , solve(cost,i+2,n,t));
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> t1(n+1,-1);
        vector<int> t2(n+1,-1);       
        return min(solve(cost,0,n,t1),solve(cost,1,n,t2));
    }
};