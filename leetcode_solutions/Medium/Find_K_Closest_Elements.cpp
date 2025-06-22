class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> heap;
        
        for (int num: arr) {
            int distance = abs(x - num);
            heap.push(pair(distance, num));
            if (heap.size() > k) {
                heap.pop();
            }
        }
        
        vector<int> ans;
        while (heap.size() > 0) {
            cout << heap.top().first << " " << heap.top().second << endl;
            ans.push_back(heap.top().second); heap.pop();
        }
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};