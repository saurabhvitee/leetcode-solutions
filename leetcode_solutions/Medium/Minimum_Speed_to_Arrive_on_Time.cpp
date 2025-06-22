class Solution {
public:
    bool checkPossibility(vector<int>& dist, double speed, double hour){
        // we need to calculate ceil(distance/speed) -> full integer hour 
        // is the only hour where train can leave.

        double hourRequiredWithThisSpeed = 0;
        
        for(int i=0; i<dist.size(); i++){
            // If it is last element, we do not care cause we can keep this in floating point.
            // Since there is no train after this 
            // so no need to wait for complete integer hour.

            if(i == dist.size()-1){
                hourRequiredWithThisSpeed += (dist[i]/speed);
                continue;
            }
            hourRequiredWithThisSpeed += ceil(dist[i]/speed);
        }

        // If hours with current speed <= total limit of hours 
        // In that case return true else false
        return hourRequiredWithThisSpeed <= hour;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        // So we know maximum integer speed can be max element in dist vector 
        // cause each train can start at an integer hour 
        // [1,3,2] -> At 3 it will give fastest answer -> 3 hours 
        // [1,3,2] -> At 3 and beyond also it will give same answer -> 3 hours 

        // But limit of hour is 10^9 so we have to check that max limit instead of maximum distance 
        
        // But it is given that maximum speed can be 10^7 

        int left = 1;
        int right = 1e7;
        // search space created.
        
        int minimumSpeed = -1;

        while(left <= right){
            // since right is inclusive 

            int mid = left + (right-left)/2;

            if(checkPossibility(dist, mid, hour)){
                minimumSpeed = mid;
                // Traverse in left to find minimum answer 
                right = mid-1; // right inclusive
            }else{
                left = mid+1;
            }
        }

        return minimumSpeed;
    }
};