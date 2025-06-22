class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sl = s.length();
        int tl = t.length();
        int i=0;
        int j=0;
        while(i<sl && j < tl)
        {
            if(s[i]==t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        if(i==sl){
            return true;
        }
        return false;
    }
};