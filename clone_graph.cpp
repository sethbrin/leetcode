/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL) {
           return NULL;
        }
        if (visited.find(node->label) != visited.end()) {
            return visited[node->label];
        }
        
        UndirectedGraphNode *copyNode = new UndirectedGraphNode(node->label);
        visited[node->label] = copyNode;
        
        vector<UndirectedGraphNode *>& copyNeighbors = copyNode->neighbors;
        vector<UndirectedGraphNode *>& neighbors = node->neighbors;
        
        for (UndirectedGraphNode* n: neighbors) {
            copyNeighbors.push_back(cloneGraph(n));
        }
        
        return copyNode;
    }
    
private:
    unordered_map<int, UndirectedGraphNode *> visited;
};
