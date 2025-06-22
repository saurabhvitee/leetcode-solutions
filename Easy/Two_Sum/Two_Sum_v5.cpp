class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n = nums.size();

        unordered_map<int,int> mpp;

        for(int i=0; i<n; i++){
            int curr = nums[i];

            if(mpp.find(target-curr) != mpp.end()){
                return {i, mpp[target-curr]};
            }

            mpp[curr] = i; //placing index in front of element 
        }

        return {-1, -1};
        
    }
};