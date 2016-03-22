class Solution {
public:

    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      if (len <= 1) {
        return 0;
      }

      int buy = prices[0];
      int sell = 0;
      for (int i=1; i<len; i++) {
        sell = max(sell, prices[i] - buy);
        buy = min(buy, prices[i]);
      }
      return sell; 
    }

};
