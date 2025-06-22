class Solution {
public:
    bool checkPossibility(vector<int>& nums, int potentialSum, int totalSplits) {
        int n = nums.size();

        int currSum = 0;
        int currSplits = 0;

        for (int i = 0; i < n; i++) {
            if (currSum + nums[i] <= potentialSum){
                currSum += nums[i];
            }else{
                currSplits++;
                currSum = nums[i];
            }
        }

        // Important part is here in this function we just want to check 
        // if chunking is possible with given potentialSum and splits should not exceed more than given splits.

        // Also for sure most optimal answer would be to split exactly into k
        // reason because if you have broken it into less than k -> largestSum -> A 
        // you can further break it down to find minimal largest Sum < A 
        // cause you have splits left in your pocket so break it and minimize it more 
        // 1 4 4, k = 3 

        // cout << currSplits+1 << " " << totalSplits << " " << potentialSum << endl;
        return currSplits+1 <= totalSplits;
    }

    int splitArray(vector<int>& nums, int k) {
        // create binary search space

        // Very important here because even if you split everything 
        // largest sum will be maximum element alone 

        // also sometimes you will not even break this in that case
        // right = totalSum 

        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);

        int ans = 0; // Minimum largest sum for which breaking is possible

        while (left <= right) {
            int mid = left + (right - left) / 2;

            bool isPossible = checkPossibility(nums, mid, k);
            if (isPossible) {
                // if possbile let's travese in mid to find minimum largest sum
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};