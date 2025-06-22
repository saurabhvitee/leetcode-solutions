class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // Sort by number of units per box, descending
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] > b[1];
        });

        int totalUnits = 0;
        for (const auto& box : boxTypes) {
            int count = min(truckSize, box[0]); // Take as many as we can
            totalUnits += count * box[1];
            truckSize -= count;
            if (truckSize == 0) break; // Truck is full
        }

        return totalUnits;
    }
};
