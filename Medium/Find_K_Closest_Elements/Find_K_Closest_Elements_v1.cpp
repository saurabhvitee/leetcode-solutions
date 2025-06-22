class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            minHeap;
        int n = 0;
        for(const int& num: arr){
            minHeap.push({abs(num-x), num});
            n++;
        }

        if(n == k) return arr;

        int count = 0;
        vector<int> ans;
        while(!minHeap.empty()){
            if(count == k){
                sort(ans.begin(), ans.end());
                return ans;
            }
            ans.push_back(minHeap.top().second);
            cout << minHeap.top().first << " " << minHeap.top().second << endl;
            minHeap.pop();
            count++;
        }

        return ans;
    }
};