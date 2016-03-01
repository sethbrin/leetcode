class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        // use map to store
        vector<int> courseIndegree(numCourses, 0);
        multimap<int, int> adjs;
        
        int tmp;
        int edges = prerequisites.size();
        for(int i=0; i<prerequisites.size(); i++) {
            courseIndegree[prerequisites[i].first] ++;
            adjs.insert(pair<int, int>(prerequisites[i].second, prerequisites[i].first));
        }
        
        vector<int> res;
        queue<int> zeroDegreeQueue;
        for (int i=0; i<numCourses; i++) {
            if (0 == courseIndegree[i]) {
                zeroDegreeQueue.push(i);
            }
        }
        
        while (!zeroDegreeQueue.empty()) {
            int tmp = zeroDegreeQueue.front();
            zeroDegreeQueue.pop();
            res.push_back(tmp);
            
            pair< multimap<int, int>::iterator,  multimap<int, int>::iterator > range = 
               adjs.equal_range(tmp);
            for ( multimap<int, int>::iterator iter = range.first; iter != range.second; ++iter) {
                if (0 == --courseIndegree[iter->second]) {
                    zeroDegreeQueue.push(iter->second);
                }
                edges --;
            }
        }
        
        if (edges == 0) {
            return res;
        } else {
            return vector<int>();
        }
    }
};
