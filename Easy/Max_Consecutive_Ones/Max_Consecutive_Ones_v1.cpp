class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0;
        int ans = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i]){
                maxLen++;
            }else{
                maxLen = 0;
            }

            ans = max(ans, maxLen);
        }
        return ans;
    }
};