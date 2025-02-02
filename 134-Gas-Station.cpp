class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalSurplus = 0, surplus = 0;
        int startIdx = 0;
        for (int i = 0; i < gas.size(); i++) {
            totalSurplus += gas[i] - cost[i];
            surplus += gas[i] - cost[i];
            if (surplus < 0) {
                startIdx = (i + 1) % gas.size();
                surplus = 0;
            }
        }
        return totalSurplus >= 0 ? startIdx : -1;
    }
};