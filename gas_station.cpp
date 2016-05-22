class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 1. if the car start from i and can not reach j, then start from k can not reach j, i < k < j,
        //    As we know, the car from i + 1 can not reach k also, otherwise the car can start from i to k,
        //    the same reason for the gas station between i and j
        // 2. if the total gas less than the cost, it can not reach
        
        int start = 0;
        int total = 0;
        int remain = 0;
        for (int i = 0; i < gas.size(); i++) {
            total += (gas[i] - cost[i]);
            if (remain < 0) {
                // try a new start
                start = i;
                remain = (gas[i] - cost[i]);
            } else {
                remain += (gas[i] - cost[i]);
            }
        }
        
        return total < 0 ? -1 : start;
    }
};
