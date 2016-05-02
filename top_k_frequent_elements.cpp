class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        for (int num: nums) {
            if (m.find(num) != m.end()) {
                m[num] ++;
            } else {
                m[num] = 1;
            }
        }
        
        auto cmp = [&m](const int lhs, const int rhs) {
            return m[lhs] > m[rhs];
        };
        
        vector<int> res;
        res.reserve(k);
        
        int ind = 0;
        for (auto iter=m.begin(); iter!=m.end(); ++iter) {
            res.push_back(iter->first);
            push_heap(res.begin(), res.end(), cmp);
            if (ind >= k) {
                pop_heap(res.begin(), res.end(), cmp);
                res.pop_back();
            } else {
                ind ++;
            }
        }
        
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};
