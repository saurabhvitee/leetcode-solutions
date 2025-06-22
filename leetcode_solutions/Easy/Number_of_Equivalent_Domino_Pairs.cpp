class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int lenV = dominoes.size();
        int count = 0;
        vector<vector<int>> freq(100, vector<int>(100,0));

        for(int i=0;i<lenV;i++){

            freq[dominoes[i][0]][dominoes[i][1]]++;

            if (dominoes[i][0] != dominoes[i][1]){
                freq[dominoes[i][1]][dominoes[i][0]]++;
            }

        }

        for (int i=0;i<100;i++){
            for (int j=0;j<100;j++){
                if( freq[i][j] > 1){
                    count = count + (freq[i][j]) * (freq[i][j]-1)/2;
                    freq[j][i]=0;
                }

            }
        }

        return count;


    }
};