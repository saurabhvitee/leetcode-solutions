class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        int ans = -1;

        for(int i=0; i<n; i++){
            int curr = nums[i];
            int sum = 0;

            while(curr > 0){
                sum += (curr%10);
                curr = curr/10;
            }

            if(mpp.find(sum) != mpp.end()){
                ans = max(ans, nums[i] + mpp[sum]);
            }

            mpp[sum] = max(nums[i], mpp[sum]);

        } 

        return ans;
    }
};