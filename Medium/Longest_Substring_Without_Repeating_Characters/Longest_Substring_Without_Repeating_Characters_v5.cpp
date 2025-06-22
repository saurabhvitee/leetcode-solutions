class Solution {
public:
    //abcc
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n==0){
            return 0;
        }
        int freq[256]={0};
        int i=0;
        int j=0;
        int len = 0;
        int ans = INT_MIN;
        
        while(i<n && j<n)
        {
            if(freq[s[j]]==0)
            {
                freq[s[j]]++;
                j++;
                len++;
            }
            else
            {
                while(freq[s[j]]!=0)
                {
                freq[s[i]]--;
                i++;
                len--;
                }
            }
            //cout << len << " " << ans << endl;
            ans = max(ans,len);
        }
        return ans;
    }
};