// I get this idea from the discussion

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> res;
        if (n <=2) {
            for (int i = 0; i < n; ++i) {
                res.push_back(i);
            }
            return res;
        }
        // first build the tree, first int is the
        unordered_map<int, unordered_set<int>> graph;
        for (auto temp : edges) {
            graph[temp.first].insert(temp.second);
            graph[temp.second].insert(temp.first);
        }
        
        // first identify the leaves
        vector<int> buf1;
        vector<int> buf2;
        
        vector<int>* leaves = &buf1;
        vector<int>* newleaves = &buf2;
        for (auto temp : graph) {
            if (temp.second.size() == 1) {
                leaves->push_back(temp.first);
            }
        }
        // delete leaves until 
        while (n > 2) {
            n -= leaves->size();
            for (auto templeave : *leaves) {
                for (auto temp : graph[templeave]) {
                    graph[temp].erase(templeave);
                    if (graph[temp].size() == 1) {
                        newleaves->push_back(temp);
                    }
                }
            }
            leaves->clear();
            swap(leaves, newleaves);
        }
        return *leaves;
    }
};
