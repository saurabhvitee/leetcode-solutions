class Solution {
public:
    vector<string> neighbors(string gene) {
        vector<string> ans;

        int n = gene.size();

        for (int i = 0; i < n; i++) {
            for (char eachChar : {'A', 'C', 'G', 'T'}) {
                string copyStr = gene;
                if (copyStr[i] != eachChar) {
                    // Change this one character to different character from allowed list.
                    copyStr[i] = eachChar;
                    ans.push_back(copyStr);
                }
            }
        }
        return ans;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        set<string> seen;

        queue<pair<string, int>> q;
        q.push(make_pair(startGene, 0));
        seen.insert(startGene);

        while (!q.empty()) {
            auto [nextGene, dist] = q.front();
            q.pop();

            if (nextGene == endGene) {
                return dist;
            }

            for (string neighborGene : neighbors(nextGene)) {
                if (seen.find(neighborGene) == seen.end()) {
                    // only process if that gene is in bank.
                    // otherwise do not process this gene.
                    if(find(bank.begin(), bank.end(), neighborGene) != bank.end()){
                        q.push(make_pair(neighborGene, dist + 1));
                        seen.insert(neighborGene);
                    }
                }
            }
        }

        return -1;
    }
};