class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {

        int n = nums.size();

        for(int i=0; i<n; i++){
            // Building the array - storing initial and final both values
            nums[i] =  nums[i] + 1000 * (nums[nums[i]] % 1000);
        }

        for (int i=0; i<n; i++){
            // fetching final value 
            nums[i] = nums[i] / 1000;
        }

        return nums;
        
    }
};