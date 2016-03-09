class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int len = x.size();
        // As notice, each cicle is a new beginning, we just need to consider one circle situation
        for (int i=3; i<len; i++) {
            // the first line cross the forth line
            if (x[i-3] >= x[i-1] && x[i] >= x[i-2]) return true;
            // the fifth line meet the first line
            if (i>=4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;
            // the sixth line cross the first line
            if (i >= 5 && x[i-2] >= x[i-4] && x[i-2] <= x[i] + x[i-4] && x[i-1] + x[i-5] >= x[i-3] && x[i-1] <= x[i-3]) return true;
        }
        return false;
    }
};
