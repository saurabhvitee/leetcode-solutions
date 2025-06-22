class Solution {
public:
    bool checkPossibility(vector<int>& candies, long long candiesPerStudent, long long k){
        // Here we will check if distribution is possible with candiesPerStudent
        // Such that all of the students are getting equal candies.

        int n = candies.size();
        long long satisfiedStudents = 0;

        for(int i=0; i<n; i++){
            long long candyInThisPile = candies[i];

            // Improved Time complexity 
            satisfiedStudents += floor(candyInThisPile/candiesPerStudent);

            // Here we are making sure every student is getting candies from 
            // same pile. -- This will cause TLE 

            // while(candyInThisPile > 0){
            //     if(candyInThisPile - candiesPerStudent >= 0){
            //         satisfiedStudents++;
            //         candyInThisPile -= candiesPerStudent;
            //     }else{
            //         break;
            //         // unused candies that we can throw away
            //     }
            // }
        }

        return satisfiedStudents >= k;
    }

    int maximumCandies(vector<int>& candies, long long k) {
        // early exit condition 
        long long totalCandies = accumulate(candies.begin(), candies.end(), 1LL * 0);

        if(k > totalCandies)
            return 0;

        // Let's create binary search space
        int left = 1;
        int right = *max_element(candies.begin(), candies.end());

        int maximumCandiesPossible = 0;
        
        while(left <= right){
            // Right inclusive 

            long long mid = left + (right-left)/2; // avoid int overflow 

            if(checkPossibility(candies, mid, k)){
                maximumCandiesPossible = mid;
                left = mid+1;
                // traverse in right cause we want to maximize candies  
            }else{
                right = mid-1;
            }
        }

        return maximumCandiesPossible;
    }
};