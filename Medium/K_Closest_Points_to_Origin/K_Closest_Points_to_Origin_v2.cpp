class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long double, vector<int>>> maxHeap;

        for(const vector<int>& point: points){
            long double distance = (point[0]*point[0]) + (point[1]*point[1]);
            distance = sqrt(distance);
            maxHeap.push({distance, point});

            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> ans;

        while(!maxHeap.empty()){
            cout << maxHeap.top().second[0] << " " << maxHeap.top().second[1] << endl;
            ans.push_back({maxHeap.top().second[0], maxHeap.top().second[1]});
            maxHeap.pop();
        }

        return ans;
    }
};