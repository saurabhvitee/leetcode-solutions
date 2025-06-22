class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // first method - Sorting
        // int n = nums.size();

        // sort(nums.begin(), nums.end());

        // int currStreak = 1;
        // int longStreak = 1;

        // for(int i=1; i<n; i++){
            
        //     if(nums[i] == (nums[i-1] + 1)){
        //         currStreak++;
        //         cout << currStreak << endl;
        //     }
        //     else if(nums[i] == nums[i-1]){
        //         continue;
        //     }
        //     else{
        //         currStreak = 1;
        //     }
        //     longStreak = max(longStreak, currStreak);
        //     //cout << currStreak << endl;
        // }

        // if(n==0) return 0;

        // return longStreak;

        // Part 2 using unordered set

        int n = nums.size();

        unordered_set<int> uniqueSet;

        for(int i=0; i<n; i++){
            uniqueSet.insert(nums[i]);
        }

        int longStreak = 0;
        for(auto it: uniqueSet){
            
            int currValue = it;
            int currStreak = 1;

            if(uniqueSet.find(currValue-1) == uniqueSet.end()){
                
                while(uniqueSet.find(currValue+1) != uniqueSet.end()){
                    currStreak++;
                    currValue++;
                }
            }

            longStreak = max(currStreak, longStreak);
        }

        if(n == 0) return 0;

        return longStreak;

    }
};