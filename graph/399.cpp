class Solution {
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        unordered_map<string, list<pair<string, double>>> graph;
        unordered_map<string, int> visited;
        
        for (int i = 0; i < values.size(); ++i) {
            auto tempeq = equations[i];
            double val = values[i];
            pair<string, double> temppair1 = make_pair(tempeq.second, val);
            graph[tempeq.first].push_back(temppair1);
            pair<string, double> temppair2 = make_pair(tempeq.first, 1/val);
            graph[tempeq.second].push_back(temppair2);
            visited[tempeq.first] = 0;
            visited[tempeq.second] = 0;
        }
        
        // use dfs to search
        double resval;
        vector<double> res;
        for (auto tempquery : queries) {
            if (graph.find(tempquery.first) == graph.end()) {
                res.push_back(-1);
            }
            else if (dfsHelp(tempquery.first, tempquery.second, graph, visited, resval)) {
                res.push_back(resval);
            }
            else {
                res.push_back(-1);
            }
            for (auto it = visited.begin(); it != visited.end(); ++it) {
                it->second = 0;
            }
        }
        return res;
    }
    
    bool dfsHelp(string src, string dest, unordered_map<string, list<pair<string, double>>> &graph, unordered_map<string, int> &visited, double& res) {
        if (src.compare(dest) == 0) {
            res = 1;
            return true;
        }
        else {
            for (auto temppair : graph[src]) {
                if ((visited[temppair.first] == 0) || (visited.find(temppair.first) == visited.end())) {
                    visited[temppair.first] = 1;
                    double tempres;
                    if (dfsHelp(temppair.first, dest, graph, visited, tempres)) {
                        res = tempres * temppair.second;
                        return true;
                    }
                }
            }
        }
        res = -1;
        return false;
    }
};
