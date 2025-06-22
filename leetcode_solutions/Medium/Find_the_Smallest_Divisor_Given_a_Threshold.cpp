class Solution {
public:
    bool checkPossibility(vector<int>& nums, double divisor, double threshold){
        int currSum = 0;

        for(double number: nums){
            currSum += ceil(number/divisor); // convert to nearest integer
        }

        // If it is below threshold it is possible with current divisor.
        return currSum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // let's create search space  

        int left = 1;
        int right = 1e6; // maximum divisor can be this 

        while(left <= right){
            int mid = left + (right-left)/2;

            if(checkPossibility(nums, mid, threshold)){
                right = mid-1; // right inclusive 
            }else{
                left = mid+1;
            }
        }

        return left; // Minimum possible value where this is possible
    }
};