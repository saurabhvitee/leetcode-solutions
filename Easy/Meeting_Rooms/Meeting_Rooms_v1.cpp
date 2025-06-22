class Solution {
public:
    bool static comparator(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[1];
    }

    bool canAttendMeetings(vector<vector<int>>& intervals) {
        int n = intervals.size();

        if(n==0) return true;

        sort(intervals.begin(), intervals.end(), comparator);

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                return false;
            }
            end = intervals[i][1];
        }
        return true;
    }
};