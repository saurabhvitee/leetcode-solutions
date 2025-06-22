class Solution {
public:
    bool checkPossibility(vector<int>& piles, double speed, long long totalHour) {
        // let's calculate hours with given speed
        // that we might take to finish whole piles of banana.

        long long hoursTakenWithGivenSpeed = 0;

        // If we want to use ceil properly we need to use double in
        // numerator/denominator then only ceil will produce correct values.

        for (double pile : piles) {
            hoursTakenWithGivenSpeed += ceil(pile / speed);
        }

        if (hoursTakenWithGivenSpeed <= totalHour)
            return true;
        else
            return false;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        // Very good binary search on solution space problem.

        // Minimum spped to eat bananas can be 1.
        // Maximum answer can be maximum of piles array.
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        // We will apply binary search on this solution space
        // Here right is inclusive since right can be our answer in worst case
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (checkPossibility(piles, mid, h)) {
                // OK so it is possible with mid bananas per hour
                // But is there any better solution available ?
                // Let's go in left and find out
                right = mid - 1; // since right is also inclusive
            } else {
                left = mid + 1;
            }
        }

        return left; // Minimum possible ans
    }
};