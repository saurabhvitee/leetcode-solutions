class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // basically I need to calc lower bound.
        int left=0, right = nums.size(); // right exclusive

        while(left < right){
            int mid = left + (right-left)/2;

            if(nums[mid] >= target){
                // Keep searching in left direction for the first index
                right = mid; // right exclusive
            }else{
                left = mid+1;
            }
        }

        return left;
    }
};