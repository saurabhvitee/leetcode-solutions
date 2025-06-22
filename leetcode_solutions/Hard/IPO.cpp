class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;

        int n = profits.size();

        for(int i=0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }

        sort(projects.begin(), projects.end());
        // This will automatically sort the array in capital order

        // Initialize a heap of size k
        priority_queue<int> maxHeap;
        int j = 0;
        for(int i=0; i<k; i++){

            // Here what are we calculating we are pushing elements in priority queue 
            // If we have enough capital to pick those projects.
            while(j<n and projects[j].first <= w){
                // cout << projects[j].second << endl;
                maxHeap.push(projects[j].second);
                j++;
            }

            // K will be popped out less than K times if heap becomes empty
            // since we need to calculate max K elements.
            if(maxHeap.empty()){
                return w;
            }
            
            // Important concept is K will be popped out exactly K times

            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};