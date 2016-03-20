class Solution {
    struct isBitOne {
       isBitOne(int ind): m_ind(ind) {};
       bool operator() (int val) {
           return (val>>m_ind) & 1;
       }
       int m_ind;
    };
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> res;
        int xorVal = 0;
        for (int num : nums) {
            xorVal ^= num;
        }
        // find the index that with bit 1
        // use the bit partition the vector into two parts, 
        // as the two elements which appear only once will set into different parts
        int ind = 0;
        while (((xorVal>>ind) & 1) == 0) {
          ind ++;
        }
        vector<int>::iterator mid = partition(nums.begin(), nums.end(), isBitOne(ind));

        int left = 0;
        for (vector<int>::iterator it=nums.begin(); it != mid; ++it) {
          left = left ^ *it;
        }
        res.push_back(left);

        int right = 0;
        for (vector<int>::iterator it=mid; it != nums.end(); ++it) {
          right = right ^ *it;
        }
        res.push_back(right);
        return res;
    }
};

