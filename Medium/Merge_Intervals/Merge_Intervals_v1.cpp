class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;

        for(int i=0; i<n; i++){

            // traverse and store start in ans array
            if(ans.empty() || intervals[i][0] > ans.back()[1]){
                // does not lie in interval
                ans.push_back(intervals[i]);
            }else{
                // lies in interval, update the previous element to extend the range 
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            }

        }

        return ans;
        
    }
};