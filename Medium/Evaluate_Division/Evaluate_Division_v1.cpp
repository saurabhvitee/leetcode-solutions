class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;
    double calculateIndividualQuery(string start, string end) {
        if (graph.contains(start) and graph.contains(end)) {

            unordered_set<string> seen;
            queue<pair<string, double>> q;

            // Let's push start in queue and seen set
            q.push({start, 1.0});
            seen.insert(start);

            while(!q.empty()){
                auto [node, ansTillThisNode] = q.front();
                q.pop();

                if(node == end){
                    return ansTillThisNode;
                }

                // go to neighbors
                for(auto [neighbor, val]: graph[node]){
                    if(seen.find(neighbor) == seen.end()){
                        // Means we are visiting this node for the very first time.
                        seen.insert(neighbor);
                        q.push({neighbor, ansTillThisNode * val});
                    }
                }
                
            }
        }

        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();

        for (int i = 0; i < n; i++) {
            string nodeA = equations[i][0];
            string nodeB = equations[i][1];
            double val = values[i];

            // Add these entries in map.
            graph[nodeA][nodeB] = val;
            graph[nodeB][nodeA] = 1 / val;
        }

        // to store answer of each queries, initialize everything with -1
        vector<double> ans = vector(queries.size(), -1.0);

        for (int i = 0; i < queries.size(); i++) {
            // Let's take every query one by one
            string queryNodeA = queries[i][0];
            string queryNodeB = queries[i][1];

            ans[i] = calculateIndividualQuery(queryNodeA, queryNodeB);
        }

        return ans;
    }
};