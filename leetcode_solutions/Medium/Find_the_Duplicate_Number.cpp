class Solution {
public:

    int small_or_equal(vector<int>& nums, int curr, int n){
            int count = 0;
            for(int i=0; i<n; i++){
                if (nums[i] <= curr){
                    count++;
                }
            }
            cout << count << " elements are less than " << curr << endl;
            return count;
        }

    int findDuplicate(vector<int>& nums) {
        
        // This is approach 1 where we will check how many numbers are less than 
        // current index 
        // int n = nums.size();

        // int low = 0;
        // int high = n;
        // int duplicate = -1;

        // while(low <= high){

        //     int mid = (low + high)/2;

        //     if(small_or_equal(nums, mid, n) > mid){
        //         duplicate = mid;
        //         high = mid-1;
        //     }else{
        //         low = mid+1;
        //     }

        // }

        // return duplicate;

        // This is approach 2 where we will use hare and tortoise algorithm

        int n = nums.size();
        int i = 0;

        int hare=nums[0];
        int tortoise=nums[0];

        // Find the intersection point
        // Since it is given that nums[i] value will be in range [0,n]
        // we can safely apply this algorithm.
        // There will be 2 arrows coming to duplicate number
        // cause that is present at 2 index
        // let us suppose we have 2 4 3 1 6 5 1
        // Here at 1 we will have 2 arrows coming towards 1
        while(true){
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];

            if(tortoise == hare){
                break;
            }
        }

        // set tortoise at start again after intersection point
        tortoise = nums[0];

        // Now increase hare and tortoise one by one and let's see where they meet
        while(tortoise != hare){
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return tortoise;

    }
};