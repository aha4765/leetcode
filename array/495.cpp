class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int totaltime = 0;
        if (timeSeries.empty()) return 0;
        int curtick = timeSeries[0];
        for (int i = 1; i < timeSeries.size(); ++i) {
            if (timeSeries[i] - timeSeries[i-1] > duration) {
                totaltime += duration;
            }
            else {
                totaltime += (timeSeries[i] - timeSeries[i-1]);
            }
        }
        totaltime += duration;
        return totaltime;
    }
};
