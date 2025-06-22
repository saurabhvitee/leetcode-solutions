class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        // key concept is to create graph.
        unordered_map<int, vector<int>> graph;

        for(int i=0;i<n;i++){
            if(i + arr[i] < n){
                graph[i].push_back(i+arr[i]);
            }

            if(i-arr[i] >= 0){
                graph[i].push_back(i-arr[i]);
            }
        }

        // Lets do BFS quickly from start index.
        set<int> seen;
        queue<int> q;
        q.push(start);
        seen.insert(start);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            if(arr[node] == 0){
                return true;
            }

            // Let's go to neighbors
            for(int neighbor: graph[node]){
                if(seen.find(neighbor) == seen.end()){
                    // unseen node
                    seen.insert(neighbor);
                    q.push(neighbor);
                }
            }
        }

        return false;
    }
};