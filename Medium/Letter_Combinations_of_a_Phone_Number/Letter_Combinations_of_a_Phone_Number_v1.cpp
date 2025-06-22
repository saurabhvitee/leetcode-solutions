class Solution {
public:
    const unordered_map<char, string> phoneMap = 
    {
        {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void backtrack(int index, string& curr, vector<string>& ans, string& digits){
        if(index >= digits.size()){
            return;
        }

        if(index == digits.size()-1){
            // We are at the end of digit.
            for(char c: phoneMap.at(digits[index])){
                curr.push_back(c);
                ans.push_back(curr);
                curr.pop_back();
            }
        }

        cout << index << endl;

        // Traverse to all the digits of current index 
        // Move further in digits then 
        string atThisDigit = phoneMap.at(digits[index]);

        for(char c: atThisDigit){
            curr.push_back(c);
            backtrack(index+1, curr, ans, digits);
            curr.pop_back();
        }

        return;
    }

    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0) return {};

        vector<string> ans;
        // string curr;

        // We need to call this backtrack function for all the starting points
        // No need of that our backtrack function can handle that actually.

        string initial = phoneMap.at(digits[0]);

        for(char c: initial){
            string curr;
            curr.push_back(c);
            // Index will be 2
            if(digits.size() == 1){
                ans.push_back(curr);
                curr.pop_back();
            }else{
                backtrack(1, curr, ans, digits);
            }
        }

        return ans;
    }
};