class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        int cnt=0;
        int k=0;
        for(int i=0;i<sl;i++){
            for(int j=k;j<tl;j++){
                if(s[i]==t[j]){
                    cnt++;
                    k=j+1;
                    break;
                }
            }
        }
        if(cnt==sl){
            return true;
        }
        return false;
    }
};