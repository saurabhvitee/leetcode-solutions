class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, int> wins;
        unordered_map<int, int> losses;

        vector<vector<int>> ans;
        ans.push_back(vector <int>());
        ans.push_back(vector <int>());


        int n = matches.size();

        for(int i=0; i<n; i++){
            wins[matches[i][0]]++;
            losses[matches[i][1]]++;
        }

        for(auto [key,val]: wins){
            cout << "Player " << key << " won " << val << " matches " << endl;
            cout << endl;

            if(losses.find(key) == losses.end()){
                ans[0].push_back(key);
            }
        }

        for(auto [key,val]: losses){
            cout << "Player " << key << " lost " << val << " matches " << endl;

            if(losses[key] == 1){
                ans[1].push_back(key);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};