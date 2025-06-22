class Solution {
    // Graph using bomb index as key instead of (x, y) coordinates
    unordered_map<int, vector<int>> graph;

public:
    long long formula(int x1, int y1, int x2, int y2) {
        // Check if 2 is within 1.
        long long val =
            1LL * (x2 - x1) * (x2 - x1) + 1LL * (y2 - y1) * (y2 - y1);
        return val;
    }

    void neighbors(vector<vector<int>>& bombs, int i, int j) {
        int cx1 = bombs[i][0], cy1 = bombs[i][1], r1 = bombs[i][2];
        int cx2 = bombs[j][0], cy2 = bombs[j][1], r2 = bombs[j][2];

        if (formula(cx1, cy1, cx2, cy2) <= 1LL * r1 * r1) {
            // This means x2,y2 lies within x1,y1 hence lets add it as neighbor.
            graph[i].push_back(j);
        }

        if (formula(cx2, cy2, cx1, cy1) <= 1LL * r2 * r2) {
            // This means x1,y1 lies within x2,y2 hence lets add it as neighbor.
            graph[j].push_back(i);
        }
        return;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                neighbors(bombs, i, j);
            }
        }

        // Now let's do BFS in graph and find maximum connected component.
        int ans = INT_MIN;

        for (int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            queue<int> q;

            q.push(i);
            seen[i] = true;

            int tempAns = 1;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                for (int neighbor : graph[curr]) {
                    // If this neighbor is unseen, push it into queue
                    if (!seen[neighbor]) {
                        tempAns++; // cause we have added node
                        q.push(neighbor);
                        seen[neighbor] = true;
                    }
                }
            }
            ans = max(ans, tempAns);
        }
        return ans;
    }
};
