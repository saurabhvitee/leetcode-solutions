class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n = cards.size();
        int ans = INT_MAX;
        unordered_map<int, int> mpp;

        bool duplicateFlag = false;

        for(int i=0; i<n; i++){
            if(mpp.find(cards[i]) != mpp.end()){
                duplicateFlag = true;
                ans = min(ans, i-mpp[cards[i]]);
            }
            
            mpp[cards[i]] = i-1;
        }
        
        if (!duplicateFlag) return -1;

        return ans;
    }
};