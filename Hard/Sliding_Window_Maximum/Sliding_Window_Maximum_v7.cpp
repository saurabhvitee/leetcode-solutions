class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        // Solution using deque

        // deque<int> deq(k);
        // vector<int> ans;

        // int n = nums.size();

        // for (int i = 0; i < n; i++) {

        //     // pop back elements from deque if you see greater elements
        //     while (!deq.empty() and nums[i] >= nums[deq.back()]) {
        //         deq.pop_back();
        //     }

        //     // Insert current element
        //     deq.push_back(i);

        //     // If you see front is k distance away from current location
        //     // remove that front
        //     while (deq.front() + k <= i) {
        //         deq.pop_front();
        //     }

        //     // finally if we have reached k-1 start adding ans;
        //     if (i + 1 >= k)
        //         ans.push_back(nums[deq.front()]);
        // }

        // return ans;

        // Solution 2 - We can solve this problem by using Dynamic programming
        // as well Bidirectional DP we can use Where maximum from left and
        // maximum from right we will compare at any given index

        int n = nums.size();

        vector<int> left = vector<int>(n, 0);
        vector<int> right = vector<int>(n, 0);

        // We will reset the max at few indexes
        // For left => if k = 3 then reset max after [0,1,2] and [3,4,5] and
        // [6,7,8] For right => if k = 3 then reset max after [8,7,6] and
        // [5,4,3] and [2,1,0]

        int maxFromLeft = INT_MIN;
        int maxFromRight = INT_MIN;

        for (int i = 0; i < n; i++) {
            // Update leftMax array in first half

            if (i == 0 or (i) % k == 0) {
                // Reset maximum here
                left[i] = nums[i];
                maxFromLeft = nums[i];
            } else {
                // for rest of the indexes
                // update maxFromLeft after comparison with current element and
                // push
                maxFromLeft = max(maxFromLeft, nums[i]);
                left[i] = maxFromLeft;
            }

            // Update rightMax array in second half with same loop

            int j = n - i - 1; // Index from right

            if (j == n - 1 or (j + 1) % k == 0) {
                // Reset maximum here
                right[j] = nums[j];
                maxFromRight = nums[j];
            } else {
                // for rest of the indexes compare current element with previous
                // maximum and push
                maxFromRight = max(maxFromRight, nums[j]);
                right[j] = maxFromRight;
            }
        }

        // Now for every window of size k we will traverse and put max(right[i],
        // left[i+k-1]) until i+k-1 is reachable
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // Only if window size is possible
            if (i + k - 1 < n) {
                ans.push_back(max(right[i], left[i + k - 1]));
            }
        }

        return ans;
    }
};