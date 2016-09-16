// 1) I need to be more familiar with the STL container
// 2) I need to redo it with dfs topology sort
// use topological sort
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        buildgraph(numCourses, prerequisites);
        return toposort();
    }
    
    int buildgraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        gsize = numCourses;
        for (auto temp : prerequisites) {
            graph[get<1>(temp)].push_back(get<0>(temp));
        }
        return 0;
    }
    
    vector<int> toposort() {
        vector<int> indegree(gsize, 0);
        
        for (map<int, list<int>>::iterator it = graph.begin(); it != graph.end(); ++it) {
            for (auto temp : it->second) {
                ++indegree[temp];
            }
        }
        
        queue<int> zdegree;
        vector<int> result;
        for (int i = 0; i < indegree.size(); ++i) {
            if (indegree[i] == 0) {
                zdegree.push(i);
            }
        }
        while (!zdegree.empty()) {
            int node = zdegree.front();
            zdegree.pop();
            result.push_back(node);
            for (auto temp : graph[node]) {
                --indegree[temp];
                if (indegree[temp] == 0) {
                    zdegree.push(temp);
                }
            }
        }
        if (result.size() == gsize) {
            return result;
        }
        else {
            return vector<int>{};
        }
    }
    
private:
    map<int, list<int>> graph;
    int gsize;
};
