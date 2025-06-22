class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mapOfOddNumbersCount;
        mapOfOddNumbersCount[0] = 1;
        int countOdd = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i]%2) countOdd++;

            // Let us assume we have 3 odds at 0th, 1st and 2nd Index and our k = 3.
            // At 3rd index we will check do we have map[3-3] = map[0] ?
            // Yes we have map[0] = 1, hence this is a valid subarray or you can say 
            // a nice subarray.
            ans += mapOfOddNumbersCount[countOdd-k];

            mapOfOddNumbersCount[countOdd]++;
        }
        return ans;
    }
};