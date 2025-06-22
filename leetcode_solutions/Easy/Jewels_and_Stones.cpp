class Solution {
public:
    int numJewelsInStones(string J, string S) 
    {
        int n = J.length();
        int m = S.length();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(J[i]==S[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};