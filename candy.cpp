class Solution {
public:
    int candy(vector<int>& ratings) {
        // 
        // 
        //     /b\
        //  a /   \   /d
        //         \c/
        //  ------------------------
        
        int size = ratings.size();
        if (size == 1) return 1;
        // swipe left and right
        vector<int> candies(size, 0);
        
        int number = 1;
        for (int i=1; i<size; i++) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = max(number++, candies[i]);
            } else {
                number = 1;
            }
        }
        number = 1;
        for (int i=size-2; i>=0; i--) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(number++, candies[i]);
            } else {
                number = 1;
            }
        }
        
        return accumulate(candies.begin(), candies.end(), size);
    }
};
