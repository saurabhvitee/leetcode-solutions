class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int newpointer = 1; // Position to insert next unique element
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[newpointer] = nums[i];
                newpointer++;
            }
        }
        return newpointer;
    }
};
