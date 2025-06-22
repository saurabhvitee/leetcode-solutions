class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> maxHeap(nums.begin(), nums.end());

        double arraySum = 0;
        for(const auto& itr: nums){
            arraySum += itr;
        }

        double newSum = 0;
        int ans = 0;
        while(newSum < (arraySum/2)){
            if(!maxHeap.empty()){
                cout << "Entering here ";
                double maxElement = maxHeap.top();
                newSum += (maxElement/2);
                maxHeap.pop();
                maxHeap.push(maxElement/2);
                ans++;
            }
            cout << newSum << endl;
        }
        while(!maxHeap.empty()) cout << maxHeap.top() << endl, maxHeap.pop();
        return ans;
    }
};