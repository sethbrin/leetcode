/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    float getK(const Point& lhs, const Point& rhs) {
        return (lhs.y - rhs.y)*1.0/(lhs.x - rhs.x);
    }
    
    int maxVal(auto m) {
        int res = 0;
        for (auto iter=m.begin(); iter!=m.end(); ++iter) {
            res = max(res, iter->second);
        }
        return res;
    }
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<float, int> m;
        
        int size = points.size();
        if (size == 0) return 0;
        
        int res = 0;
        for (int i=0; i<size; i++) {
            m.clear();
            int same = 0;
            int sameY = 0;
            const Point& pointI = points[i];
            for (int j=i+1; j<size; j++) {
                const Point& pointJ = points[j];
                if (pointI.x == pointJ.x) {
                    if (pointI.y == pointJ.y) {
                        same ++;
                    } else {
                        // a special case, equal y, but x is not equal, it can not use getK to compute K
                        sameY ++;
                    }
                } else {
                    m[getK(points[i], points[j])] ++;
                }
            }
            
            res = max(res, max(sameY, maxVal(m)) + same + 1);
        }
        
        return res;
    }
};
