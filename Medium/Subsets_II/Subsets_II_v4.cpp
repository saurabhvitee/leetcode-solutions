class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        if(index > nums.size()){
            return;
        }

        // Since we need to calculate subsets 
        // We need to add all the nodes 
        // Not just the leaf nodes 
        ans.push_back(curr);

        for(int i=index;i<nums.size();i++){
            // we do not want certain element twice for certain kth position 
            // as explained in parent function.

            // To use this kind of concept array needs to be sorted in one order.
            if(i > index and nums[i] == nums[i-1])
                continue;
            
            curr.push_back(nums[i]); // Choose
            backtrack(i+1, nums, curr, ans); // backtrack 
            curr.pop_back(); // Unchoose
        }

        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Here also we do not want to pick certain element 2 twice for kth position.

        // [1,2,2] => [1,2,2], [2,2] will be allowed since 2 is at k and k+1 positions 
        // [1,2,2] => [1,2] this will be not allowed twice with 2 different 2's since 
        // We need to put 2 at kth position no matter how many 2's are there

        // in subsets problem all the numbers were unique in input array so we didn't face this problem

        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(0,nums, curr, ans);
        return ans;
    }
};