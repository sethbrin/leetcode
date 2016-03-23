class Solution {
public:
   int maxProfit(int k, vector<int>& prices) {
        if (k <= 0) {
            return 0;
        }
        
        int size = prices.size();
        // if k >= n/2 means that we can use the method in the buy version 2
        // we can just think that the transactions are unlimited
        if (k >= size/2) {
            int maxprofit = 0;
            
            for (int i=1; i<size; i++) {
                maxprofit += (prices[i] - prices[i-1]) > 0 ? (prices[i] - prices[i-1]) : 0; 
            }
            return maxprofit;
        }
        int* buy = new int[k];
        int* sell = new int[k];
        for (int i=0; i<k; i++) {
            sell[i] = 0;
            buy[i] = INT_MIN;
        }

        for (int price: prices) {
            for (int i=k-1; i>=1; i--) {
                sell[i] = max(sell[i], price + buy[i]);
                buy[i] = max(buy[i], sell[i-1] - price);
            }
            sell[0] = max(sell[0], price + buy[0]);
            buy[0] = max(buy[0], -price);
        }

        return sell[k-1];
    }
};
