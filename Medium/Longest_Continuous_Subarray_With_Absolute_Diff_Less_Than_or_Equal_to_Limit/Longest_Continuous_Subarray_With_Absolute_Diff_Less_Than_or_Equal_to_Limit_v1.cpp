class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        deque<int> maxd;
        deque<int> mind;

        int n = nums.size();
        int ans = 0;
        int left = 0;

        for(int right=0; right<n; right++){
            // Build maxd we will add elements only if it is greater
            // So pop all the smaller elements
            while(!maxd.empty() and nums[right] > maxd.back()){
                maxd.pop_back();
            }

            // Build mind we will add elements only if it is smaller
            // So pop all the greater elements
            while(!mind.empty() and nums[right] < mind.back()){
                mind.pop_back();
            }

            // Insert current elements in mind and maxd 
            // since answer might lies in right half of current elements
            mind.push_back(nums[right]);
            maxd.push_back(nums[right]);

            // Check if it satisfies the condition
            // If not we will try to remove elements from front

            while((maxd.front() - mind.front()) > limit){
                // So now we know our max - min > limit 
                // we need to remove elements from left if front == left

                if(mind.front() == nums[left]) mind.pop_front();
                if(maxd.front() == nums[left]) maxd.pop_front();

                left++;
            }

            ans = max(ans, (right-left+1));
        }

        return ans;
    }
};