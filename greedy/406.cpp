// get answer from discussion, be familiar with stl and lambda

// Get the solution from discussion

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), [](pair<int, int>p1, pair<int, int>p2) {return ((p1.first > p2.first) || ((p1.first == p2.first) && (p1.second < p2.second)));});
        vector<pair<int, int>> res;
        for (auto temp : people) {
            res.insert(res.begin() + temp.second, temp);
        }
        return res;
    }
};
