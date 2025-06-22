class Solution {
public:
    void backtrack(string& curr, vector<string>& ans, int openingBrackets, int closingBrackets, int n){
        if(curr.size() == 2*n){
            // Means we have reached till valid permutation.
            ans.push_back(curr);
        }

        // Now we will do backtracking 
        if(openingBrackets < n){
            // Add opening bracket and move on

            curr += '('; // Choose
            backtrack(curr, ans, openingBrackets+1, closingBrackets, n); // Recurse to next state
            curr.pop_back(); // Unchoose there might be the case of closing bracket
        }

        if(openingBrackets > closingBrackets){
            // Make sure this is the example of double backtracking on the basis of condition 
            // We will add closing bracket only if previous opening brackets are more 

            curr += ')'; // Choose the element 
            backtrack(curr, ans, openingBrackets, closingBrackets+1, n); // Recurse to next state 
            curr.pop_back(); // Unchoose the element
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr = "";
        backtrack(curr, ans, 0, 0, n);
        return ans;
    }
};