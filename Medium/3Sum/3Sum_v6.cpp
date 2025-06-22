class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int target = 0;

        for(int i=0; i < (n-1); i++){
            int left = i+1;
            int right = n-1;

            // Skipping duplicates for starting index for a triplet
            // If [-2, -2, 0, 1, 1] ---> Valid tripelt [-2, 1, 1]
            // For next -2 we will skip the iteration

            if(i!=0 && nums[i-1] == nums[i]) continue;

            while(left < right){
                int sum = nums[i];
                sum += nums[left];
                sum += nums[right];
                
                if(sum == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // If a valid pair found we will skip pointers until we have same values
                    // -1 0 0 0 1 --> Valid triplet here is [-1, 0, 1]
                    // Now let's see what are we doing once after finding pair
                    // we will increase left pointer all the way up to last 0 
                    // cause we do not want to include that into our triplet.

                    while(left < right && nums[left-1] == nums[left]) left++;
                    while(left < right && nums[right+1] == nums[right]) right--;
                }
                else if(sum < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return ans;
    }
};