class Solution {
    static inline bool cmp(int left, int right) {
        string left_str = to_string(left);
        string right_str = to_string(right);
        
        // nice
        return (left_str + right_str).compare(right_str + left_str) > 0;
    }
public:
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        
        if (size == 0) {
            return "";
        }
        if (size == 1) {
            return to_string(nums[0]);
        }
        
        sort(nums.begin(), nums.end(), cmp);
        
        // if the largest is "0", then return 0, as 00 is not a number
        if (nums[0] == 0) {
            return "0";
        }
        string res="";
        for (int i=0; i<size; i++) {
            res += to_string(nums[i]);
        }
        
        return res;
    }
};
