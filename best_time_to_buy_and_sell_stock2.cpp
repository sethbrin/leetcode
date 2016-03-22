class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // As buy in day i and sell in day j
        // the profit is prices[j] - prices[i] = (prices[j]-prices[j-1]) + ...(prices[i+1] - prices[i])
        // if there exists k that have prices[k+1] - prices[k] < 0, we can just split it, 
        // that we buy in day i and sell in day k, and buy in day k+1 and sell in day j, we will get more profit

        int len = prices.size();

        if (len <= 1) {
            return 0;
        }

        int maxprofit = 0;
        for (int i=1; i<len; i++) {
            maxprofit += (prices[i] - prices[i-1]) > 0 ? (prices[i] - prices[i-1]) : 0;
        }
        return maxprofit;
    }
};
