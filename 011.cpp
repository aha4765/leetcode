// My solution, naive and not efficient

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0; i < height.size(); ++i) {
            for (int j = i+1; j < height.size(); ++j) {
                if (max < (j-i)*(height[i] < height[j] ? height[i] : height[j])) {
                    max = (j-i)*(height[i] < height[j] ? height[i] : height[j]);
                }
            }
        }
        return max;
    }
};

// From discussion

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        
        int water = 0;
        while (left <= right) {
            water = max(water, min(height[right], height[left]) * (right - left));
            if (height[right] < height[left]) {
                --right;
            }
            else if (height[right] > height[left]) {
                ++left;
            }
            else {
                --right;
                ++left;
            }
        }
        return water;
    }
};
