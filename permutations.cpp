class Solution {

    typedef vector<int>::iterator IntIterator;
private:
    bool next_permutation1(IntIterator start, IntIterator end) {
        if (start == end) return false;
        IntIterator i = end;
        i --;
        if (start == i) return false; // only one elements

        while (true) {
            IntIterator j = i;
            i -- ;

            // if the before element is less then later one
            if (*i < *j) {
                j = end;
                while (!(*i < *--j)) {}
                iter_swap(i, j);
                reverse(i+1, end); // reverse from j to the end
                return true;
            }

            if (i == start) {
                return false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        sort(nums.begin(), nums.end());

        do{
            res.push_back(nums);
        } while(next_permutation1(nums.begin(), nums.end()));

        return res;

    }
};
