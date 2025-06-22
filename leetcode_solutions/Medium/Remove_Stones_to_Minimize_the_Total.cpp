class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> maxHeap(piles.begin(), piles.end());

        for (int i = 0; i < k; i++) {
            int top = maxHeap.top();

            maxHeap.pop();

            maxHeap.push(top - ceil(top / 2));
        }
        int sum = 0;
        while (!maxHeap.empty())
            sum += maxHeap.top(), maxHeap.pop();
        return sum;
    }
};