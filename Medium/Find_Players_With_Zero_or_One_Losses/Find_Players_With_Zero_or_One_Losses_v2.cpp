class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        // unordered_map<int, int> wins;
        unordered_map<int, int> losses;

        vector<vector<int>> ans;
        ans.push_back(vector <int>());
        ans.push_back(vector <int>());


        int n = matches.size();

        for(int i=0; i<n; i++){
            int winner = matches[i][0];
            int loser = matches[i][1];

            if(losses.find(winner) == losses.end()){
                // If that player has not lost any matches
                // We need to make sure it's loss count is ZERO
                losses[winner] = 0;

                // Otherwise we will not have any winners
            }
            // wins[matches[i][0]]++;
            losses[loser]++;
        }

        // for(auto [key,val]: wins){
        //     cout << "Player " << key << " won " << val << " matches " << endl;
        //     cout << endl;

        //     if(losses.find(key) == losses.end()){
        //         ans[0].push_back(key);
        //     }
        // }

        for(auto [key,val]: losses){
            // cout << "Player " << key << " lost " << val << " matches " << endl;

            // if(losses[key] == 1){
            //     ans[1].push_back(key);
            // }

            if (val == 0){
                // Winners only with ZERO losses.
                ans[0].push_back(key);
            }else if(val == 1){
                // Player with exact ONE loss.
                ans[1].push_back(key);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());

        return ans;
    }
};