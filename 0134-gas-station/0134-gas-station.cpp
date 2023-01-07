class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        int in = 0;
        int current_gas = 0;
        int total_g = 0, total_c = 0;
        for (int i=0;i<n;i++) {
            total_g += gas[i];
            total_c += cost[i];
            current_gas += gas[i]-cost[i];
            if (current_gas<0) {
                in = i+1;
                current_gas=0;
            }
            
        }
        if (total_g < total_c) {
            return -1;
        }
        return in;
    }
};