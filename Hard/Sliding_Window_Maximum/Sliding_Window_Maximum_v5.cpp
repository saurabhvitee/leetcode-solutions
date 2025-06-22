class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> deq(k);
        vector<int> ans;

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            // pop back elements from deque if you see greater elements
            while (!deq.empty() and nums[i] >= nums[deq.back()]) {
                deq.pop_back();
            }

            // Insert current element
            deq.push_back(i);

            // If you see front is k distance away from current location
            // remove that front
            if (deq.front() + k == i) {
                deq.pop_front();
            }

            // finally if we have reached k-1 start adding ans;
            if (i + 1 >= k)
                ans.push_back(nums[deq.front()]);
        }

        return ans;
    }
};