class Solution {
public:
    void combinationsBacktracking(int start, int n, int k, vector<int>& curr, vector<vector<int>>& ans){

        if(curr.size() == k){
            // We need subsets of size k
            // Input array is [1,n] 
            ans.push_back(curr);
        }

        // Traverse from 1 to n
        // Jump to next element by choosing it 
        // Explore using backtracking function 
        // Unchoose and let for loop do the magic 

        for(int i=start; i<=n; i++){
            // n has to be exclusive as it is given in question [1,n]
            
            // Here we are using index to skip duplicates.
            curr.push_back(i); // Choose

            combinationsBacktracking(i+1, n, k, curr, ans); // Traverse to next step explore 

            curr.pop_back(); // Unchoose
        }

        // Here we do not need to add base case since we are carefully calling 
        // recursive function within for loop 
        // Had there been a case of no for loop, in that case we need base case 
        // to stop recursion. 

        return;
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        combinationsBacktracking(1,n,k,curr,ans);
        return ans;
    }
};