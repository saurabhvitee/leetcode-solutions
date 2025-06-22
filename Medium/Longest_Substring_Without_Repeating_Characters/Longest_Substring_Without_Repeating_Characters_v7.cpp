class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        int ans = 0;
        int left=0, right=0;
        vector<int> indexMap(256, -1); // Initializing a vector or frequency array

        while(right < n){

            if(indexMap[s[right]] != -1){
                // Element exists already, we need to shift our left
                left = max(indexMap[s[right]]+1, left);
                // Here we are taking max of (left, freq[s[right]]+1)
                // As we do not want left to move backwards
            }

            ans = max(ans, right-left+1);

            // add index in frequency array
            indexMap[s[right++]] = right;

        }

        return ans;
        
    }
};