class Solution {
public:
    vector<string> neighbors(string lockState) {
        // generate all possible nearby lock state
        vector<string> ans;

        for (int i = 0; i < 4; i++) {
            for (int change : {-1, 1}) {
                string convertDiffState = lockState;
                int currNum = convertDiffState[i] - '0'; // calculate the number at particular index.
                if (currNum == 0 and change == -1) {
                    convertDiffState[i] = '9';
                } else if (currNum == 9 and change == 1) {
                    convertDiffState[i] = '0';
                } else {
                    convertDiffState[i] = (currNum + change) + '0'; // Create char from number 
                }
                ans.push_back(convertDiffState);
            }
        }

        return ans;
    }

    int openLock(vector<string>& deadends, string target) {
        // Let's see if 0000 is not in deadends.

        for (auto deadend : deadends) {
            if (deadend == "0000")
                return -1;
        }

        queue<pair<string, int>> q; // So at every state I can track distance.
        q.push({"0000", 0});

        // Add deadends as seen states in your seen set.
        unordered_set<string> seen(deadends.begin(), deadends.end());

        seen.insert("0000"); // If you have difficulty while creating
        // perfect seen array you can use set in these cases.

        while(!q.empty()){
            auto [lockState, distance] = q.front();
            q.pop();

            // Check if this is target
            if(lockState == target){
                return distance;
            }

            // Now is the time to visit lockState's neighbors
            // There will be 8 neighbors.

            for(string neighbor: neighbors(lockState)){
                if(seen.find(neighbor) == seen.end()){
                    // First time you are seeing this node.
                    seen.insert(neighbor);
                    q.push({neighbor, distance+1});
                }
            }
        }

        return -1;
    }
};