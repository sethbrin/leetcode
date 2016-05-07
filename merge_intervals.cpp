/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool cmp (const Interval& lhs, const Interval& rhs) {
        return lhs.start < rhs.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        if (intervals.empty()) return res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        res.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++) {
            Interval& back = res.back();
            if (back.end >= intervals[i].start) {
                back.end = max(intervals[i].end, back.end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        
        return res;
    }
};
