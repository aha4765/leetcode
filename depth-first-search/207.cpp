// same as 210.cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0) return true;
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
    
    bool toposort() {
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
            return true;
        }
        else {
            return false;
        }
    }
    
private:
    map<int, list<int>> graph;
    int gsize;
};
