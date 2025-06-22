class Solution {
public:
    bool canConstruct(string ro, string mo) {
        int r = ro.length();
        int m = mo.length();
        int freq[26]={0};
        for(int i=0;i<r;i++){
            freq[ro[i]-'a']++;
        }
        
        for(int i=0;i<m;i++){
            freq[mo[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                return false;
            }
        }
        return true;
    }
};