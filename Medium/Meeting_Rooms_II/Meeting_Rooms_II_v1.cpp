class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int> starts(n, 0);
        vector<int> ends(n, 0);

        for (int i = 0; i < n; i++) {
            starts[i] = intervals[i][0];
            ends[i] = intervals[i][1];
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int confRooms = 1;
        int ans = 1;

        int endPointer = 0;
        int startPointer = 1;

        while (startPointer < n) {
            if (starts[startPointer] < ends[endPointer]) {
                confRooms++;
                startPointer++;
            } else {
                confRooms--;
                endPointer++;
            }
            ans = max(ans, confRooms);
        }
        return ans;
    }
};