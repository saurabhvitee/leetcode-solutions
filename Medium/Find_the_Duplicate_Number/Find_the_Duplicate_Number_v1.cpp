class Solution {
public:

    int small_or_equal(vector<int>& nums, int curr, int n){

            int count = 0;
            for(int i=0; i<n; i++){
                if (nums[i] <= curr){
                    count++;
                }
            }
            return count;
        }

    int findDuplicate(vector<int>& nums) {

        int n = nums.size();

        int low = 0;
        int high = n;
        int duplicate = -1;

        while(low <= high){

            int mid = (low + high)/2;

            if(small_or_equal(nums, mid, n) > mid){
                duplicate = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }

        }

        return duplicate;

        
    }
};