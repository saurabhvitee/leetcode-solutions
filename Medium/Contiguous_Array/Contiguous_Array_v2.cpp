class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mpp;

        // We store this if whole array has to be considered
        // 0 0 0 1 1 1 -> array
        // -1 -2 -3 -2 -1 0 -> prefixArray
        // we have to put one entry mpp[0] = -1
        // So our answer will become 5 - (-1) = 6 (maxLen)

        mpp[0] = -1;
        int prefixSum = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i])
                prefixSum += 1;
            else
                prefixSum -= 1;

            if (mpp.find(prefixSum) == mpp.end()) {
                // Store only first occurence 
                // Since we need to find maximum so other occurences are 
                // useless to store
                mpp[prefixSum] = i;
            } else {
                maxLen = max(maxLen, i - mpp[prefixSum]);
            }
        }
        return maxLen;
    }
};