class Solution {
    
    // use list<list<int>> to represent the graph
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        set<int> visited;
        vector<vector<int>> graph(1001, vector<int>());
        
        for (vector<int> edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            visited.clear();
            
            if (dfs(graph, edge[0], visited, -1)) {
                return edge;
            }
        }
        return vector<int>(-1,-1);
    }
    
    // use dfs to find cycle
    bool dfs(vector<vector<int>> graph, int src, set<int>& visited, int parent) {
        visited.insert(src);
        
        for (int adj : graph[src]) {
            if (visited.count(adj) == 0) {
                if (dfs(graph, adj, visited, src)) {
                    return true;
                }
            }
            else if (adj != parent) {
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:   
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> parent = vector<int>(1001, -1);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            while (parent[u] != -1) {u = parent[u];}
            while (parent[v] != -1) {v = parent[v];}
            if (u == v) {
                return edge;
            }
            else {
                parent[u] = v;
            }
        }
        return vector<int>(-1, -1);
    }
};
