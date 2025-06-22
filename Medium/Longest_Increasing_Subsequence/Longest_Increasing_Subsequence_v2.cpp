class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // // O(N^2) solution

        // // Let's initialize dp array
        // // As if array is strictly decreasing order
        // // output at every index will be 1
        // vector<int> dp = vector<int>(n, 1);

        // int maximumLengthofLIS = 1;

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < i; j++) {
        //         // place answer for every dp[i]
        //         // only if nums[j] > nums[i]
        //         if (nums[i] > nums[j]) {
        //             dp[i] = max(dp[i], dp[j] + 1);
        //             maximumLengthofLIS = max(maximumLengthofLIS, dp[i]);
        //         }
        //     }
        // }

        // return maximumLengthofLIS;

        // Optimized approach
        vector<int> subsequence;

        for (int i = 0; i < n; i++) {
            if ((subsequence.size() == 0) or (subsequence.back() < nums[i])) {
                subsequence.push_back(nums[i]);
            } else {
                // Replace this element with lower_bound
                // Since this array is sorted we can use lower_bound 
                int lowerBoundIndex = lower_bound(subsequence.begin(), subsequence.end(), nums[i]) - subsequence.begin();

                // This will unlock any future possibility 
                subsequence[lowerBoundIndex] = nums[i];
            }
        }

        return subsequence.size();
    }
};