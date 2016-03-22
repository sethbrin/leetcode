class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy[2] = {INT_MIN, INT_MIN};
        int sell[2] = {0, 0};

        for (int price: prices) {
            sell[1] = max(sell[1], price + buy[1]);
            buy[1] = max(buy[1], sell[0] - price);
            sell[0] = max(sell[0], price + buy[0]);
            buy[0] = max(buy[0], -price);
        }
        return sell[1];
    }

};
