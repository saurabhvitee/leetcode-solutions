class Solution {
public:
    int upperBound(vector<int>& nums, int target) {
        int left = 0, right = nums.size(); // right is exclusive

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] <= target) {
                // mid is too small (equal is also not acceptable for
                // upper_bound)
                left = mid + 1;
            } else {
                // potential candidate
                right = mid;
            }
        }

        return left; // first index where nums[i] > target
    }

    // Speical upper_bound code labeled as lowerBound 
    
    // int lowerBound(vector<int>& nums, int target){
    //     int left=0, right=nums.size(); // right exclusive

    //     while(left < right){
    //         // calculate mid
    //         int mid = left + (right-left)/2;
    //         if(nums[mid] == target){
    //             return mid+1;
    //             // Since there are exact mid+1 elements are smaller
    //         }
    //         else if(nums[mid] < target){
    //             left = mid+1;
    //         }else{
    //             right = mid; // right exclusive
    //         }
    //     }
    //     return left; // if not found in that case return left - lowerbound ==
    //     upperbound

    // }

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();

        // Sort the array so we can apply binary search in this space
        sort(nums.begin(), nums.end());

        // Since nums[i] >= 1, prefixSum array will always contains unique
        // elements.
        for (int i = 1; i < n; i++) {
            nums[i] += nums[i - 1];
        }

        int m = queries.size();
        for (int i = 0; i < m; i++) {
            queries[i] = upperBound(
                nums, queries[i]); // 0 Based indexing will return index
        }

        return queries;
    }
};