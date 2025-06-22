class Solution {
public:
    string digits = "0123456789";

    void backtrack(int index, int n, int k, string& curr, vector<int>& ans){
        if(curr.size() == n){
            // Convert current string to number
            ans.push_back(stoi(curr));
            return;
        }

        // Traverse in digits array 
        for(int i=0;i<digits.size();i++){
            // Check if this is first index 0 can not be added
            // Or check if string is empty 

            if(curr.size() == 0 and i == 0){
                // We will not add 0 at start index 
                continue;
            }

            if(curr.size() == 0 and i != 0){
                // Free to choose this element actually 
                // since there is nothing to compare 
                curr += (digits[i]);
                backtrack(index+1, n, k, curr, ans);
                curr.pop_back();
                continue;
            }

            if(curr.size() > 0){
                int diff = abs((curr.back()-'0') - (digits[i]-'0'));

                if(diff == k){
                    // then only we will choose this ith element in our answer 
                    curr.push_back(digits[i]);
                    backtrack(index+1, n, k, curr, ans);
                    curr.pop_back();
                }
            }
        }

        return;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans;
        string curr = "";
        backtrack(0, n, k, curr, ans);
        return ans;
    }
};