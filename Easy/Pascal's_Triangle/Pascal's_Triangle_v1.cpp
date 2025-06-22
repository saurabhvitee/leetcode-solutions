class Solution {
public:

    vector<vector<int>> generate(int numRows) {

        int n = numRows;

        vector<vector<int>> ans;

        ans.push_back({1});

        if(n>1){
            ans.push_back({1,1});
        }

        for(int i=3;i<=n;i++){
            vector<int> tempList;

            tempList.push_back(1);

            for(int j=2;j<=i-1;j++){

                tempList.push_back(ans[i-2][j-2] + ans[i-2][j-1]);

            }
            tempList.push_back(1);
            ans.push_back(tempList);
        }

        return ans;
    }
};