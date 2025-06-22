class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // first method - Sorting
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int currStreak = 1;
        int longStreak = 1;

        for(int i=1; i<n; i++){
            
            if(nums[i] == (nums[i-1] + 1)){
                currStreak++;
                cout << currStreak << endl;
            }
            else if(nums[i] == nums[i-1]){
                continue;
            }
            else{
                currStreak = 1;
            }
            longStreak = max(longStreak, currStreak);
            //cout << currStreak << endl;
        }

        if(n==0) return 0;
        
        return longStreak;

    }
};