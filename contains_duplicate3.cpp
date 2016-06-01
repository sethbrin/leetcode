class Solution {
private:
    static bool cmp(const pair<long, int>& lhs, const pair<long, int>& rhs) {
        return lhs.first < rhs.first;
    }
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int size = nums.size();
        if (size < 2 || t < 0 || k <= 0) return false;
        
        vector<pair<long, int>> numsWithIndex;
        for (int i = 0; i < size; i++) {
            numsWithIndex.push_back(make_pair(nums[i], i));
        }

        sort(numsWithIndex.begin(), numsWithIndex.end(), cmp);
        
        // assert t > 0 and k > 0
        for (int i = 0; i < size; i++) {
            auto start = lower_bound(numsWithIndex.begin(), numsWithIndex.end(), make_pair((long)nums[i] - t, 0), cmp);
            auto end = upper_bound(numsWithIndex.begin(), numsWithIndex.end(), make_pair((long)nums[i] + t, 0), cmp);
            
            
            for (auto iter = start; iter != end; ++iter) {
                if (iter->second != i && abs(iter->second - i) <= k) return true;
            }
        }
        return false;
    }
};
