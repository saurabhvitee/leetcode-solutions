class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<pair<int, int>> frequencyArray;
        int freq = 1;
        for (int i = 0; i < n; i++) {

            if (i == (n - 1)) {
                frequencyArray.push_back({freq, arr[i]});
                break;
            }

            if (arr[i] == arr[i + 1]) {
                freq++;
            } else {
                frequencyArray.push_back({freq, arr[i]});
                freq = 1;
            }
        }
        sort(frequencyArray.begin(), frequencyArray.end());

        n = frequencyArray.size();

        int count = 0;
        int i = 0;

        // Need to remove exactly k elements
        // But I need to remove unique elements first
        // I guess I have to create a map and sort it from
        // less frequency to more frequency....
        while (i < n) {
            int freq = frequencyArray[i].first;
            int limitRemaining = k - count;

            if (limitRemaining <= 0) {
                break;
            }

            if (freq <= limitRemaining) {
                count = count + freq;
                frequencyArray[i].first = 0;
            } else {
                count = count + limitRemaining;
            }
            i++;
        }

        int ans = 0;
        for (const auto& each : frequencyArray) {
            if(each.first > 0) ans++;
        }

        return ans;
    }
};