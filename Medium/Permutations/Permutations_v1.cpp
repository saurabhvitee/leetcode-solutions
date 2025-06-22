class Solution {
public:
    void permutationFunction(vector<int>& nums, vector<int>& curr, vector<vector<int>>& ans){
        // Base case for backtrack 
        if(curr.size() == nums.size()){
            // you have explored all the numbers with one permutation
            ans.push_back(curr);
            return; // End the recursion
        }

        for(int number: nums){
            // for every number let's add it in our curr (temporary ans for 1 permutation)
            // only if you have not seen that previously

            // Not finding in vector is O(n) time but not using extra space
            // You can use O(n) set which can find in O(1) time complexity 

            if(find(curr.begin(), curr.end(), number) == curr.end()){
                // we have not added number in curr yet, lets add it now then
                curr.push_back(number);
                permutationFunction(nums, curr, ans); // Recursive call 
                // Not in backtrackiing problems we generally do not modify curr while calling recursion 
                // we do-undo modify before and after recursion call 

                // Undo the modification - pruning - basically backtrack
                curr.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // Backtracking so let's create ans 2D vector to store permutations.
        vector<vector<int>> ans;
        // Let's create a curr variable which will be used for 1 permutation at a time
        vector<int> curr;

        permutationFunction(nums, curr, ans);

        // since we are passing reference of ans variable it will be populated after function 
        // completes 
        return ans;
    }
};