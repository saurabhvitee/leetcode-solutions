class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(); // right is exclusive

        int left = 0, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid; // since right is exclusive 
        }
        return -1;
    }
};