class LRUCache {
    unordered_map<int, list<pair<int, int>>::iterator> m_map;
    int m_capacity;
    list<pair<int, int>> m_list;
    
    pair<int, int> moveFront(int key) {
        auto pos = m_map[key];
            
        auto res = *pos;
        m_list.erase(pos);
        m_list.push_front(res);
        
        return res;
    }
public:
    LRUCache(int capacity) : m_capacity(capacity){
    }
    
    int get(int key) {
        if (m_map.find(key) == m_map.end()) {
            return -1;
        } else {
            auto pos = m_map[key];
            int res = pos->second;
            
            m_list.erase(pos);
            m_list.push_front(*pos);
            m_map[key] = m_list.begin();
            
            return res;
        }
    }
    
    void set(int key, int value) {
        if (m_map.find(key) == m_map.end()) {
            if (m_map.size() == m_capacity) {
                // remove the least recently used item
                m_map.erase(m_list.back().first);
                m_list.pop_back();
            }
            m_list.push_front(make_pair(key, value));
            m_map.insert(make_pair(key, m_list.begin()));
        } else {
            auto pos = m_map[key];
            m_list.erase(pos);
            m_map.erase(key);
            
            m_list.push_front(make_pair(key, value));
            m_map.insert(make_pair(key, m_list.begin()));
        }
    }
};
