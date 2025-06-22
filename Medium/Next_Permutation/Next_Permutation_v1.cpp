class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // find the breakpoint
        int n = nums.size();
        int ind = -1;

        for(int i=n-2;i>=0;i--){

            if (nums[i] < nums[i+1]){

                ind = i;
                break;
            }
        }
        
        // if breakpoint does not exist
        if (ind == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        // find the next greater element with breakpoint
        // traverse from the back 

        for(int i=n-1;i>ind;i--){
            if (nums[i] > nums[ind]){
                swap(nums[ind], nums[i]);
                break;
            }
        }

        // reverse the remaining array
        reverse(nums.begin()+ind+1, nums.end());
        return;

    }
};