class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> minHeap(sticks.begin(),
                                                               sticks.end());

        int totalCost = 0;
        while (minHeap.size() > 1) {
            int stick1 = minHeap.top();
            minHeap.pop();

            int stick2 = minHeap.top();
            minHeap.pop();
        
            minHeap.push(stick1 + stick2);

            totalCost += (stick1 + stick2);
        }
        return totalCost;
    }
};