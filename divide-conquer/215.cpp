// must practice the code of quick sort, I did not come up with the code myself even after knowing using qs
// check other's solution

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0; 
        int right = nums.size() - 1;
        int pos = 0;
        while ((pos = partition(nums, left, right)) != (k - 1)) {
            if (pos < (k - 1)) {
                left = pos + 1;
            }
            else {
                right = pos - 1;
            }
        }
        return nums[k-1];
    }
    
    int partition(vector<int>& nums, int start, int end) {
        int i = start+1;
        int j = end;
        int pivot = nums[start];
        while (i <= j) {
            if ((nums[i] < pivot) && (nums[j] > pivot)) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            if (nums[i] >= pivot) {
                ++i;
            }
            if (nums[j] <= pivot) {
                --j;
            }
        }
        
        int temp = nums[j];
        nums[j] = nums[start];
        nums[start] = temp;
        return j;
    }
};
