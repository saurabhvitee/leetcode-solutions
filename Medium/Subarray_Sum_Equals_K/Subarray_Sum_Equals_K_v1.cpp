class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;


        // This is very important since
        // If any element is equal to k
        // that single element is also a subarray 
        // we need to count that as well
        mpp[0] = 1;

        int n = nums.size();
        int prefixSum = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            prefixSum += nums[i];

            if(mpp.find(prefixSum-k) != mpp.end()){
                ans += mpp[prefixSum-k];
            }

            mpp[prefixSum]++;
        }
        return ans;
    }
};