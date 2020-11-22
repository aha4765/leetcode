class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        matrix = vector<vector<int>>(size, vector<int>(size, -1));
        int sum = 0;
        for (const int temp : nums) {
            sum += temp;
        }
        int thh = 0;
        if (sum % 2 == 0) {
            thh = sum/2;
        }
        else {
            thh = sum/2+1;
        }
        if (getsum(nums, 0, size-1) >= thh) {
            return true;
        }
        else {
            return false;
        }
    }
    
private:
    vector<vector<int>> matrix;
    int getsum(const vector<int>& num, int start, int end) {
        if (start > end) {
            return 0;
        }
        else if (matrix[start][end] != -1) {
            return matrix[start][end];
        }
        else {
            matrix[start][end] = max(num[start]+min(getsum(num, start+2, end), getsum(num, start+1, end-1)), 
                                     num[end]+min(getsum(num, start, end-2), getsum(num, start+1,end-1)));
            return matrix[start][end];
        }
    }
};
