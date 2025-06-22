class Solution {
public:
    bool isPalindrome(string s) 
    {
        string saurabh = "";
        
        int l =  s.length();
        
        for(int i=0;i<l;i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                int c = s[i];
                saurabh+=c;
            }
            
            else if(s[i]>=65 && s[i]<=90)
            {
                int c = s[i];
                saurabh+=c;
            }
            
            else if(s[i]>=97 && s[i]<=122)
            {
                int c = s[i]-32;
                saurabh+=c;
            }
            else
            {
                continue;
            }
        }
        
        int n = saurabh.length();
        int m = n-1;
        int i = 0;
        int flag = 0;
        while(i < m)
        {
            if(saurabh[i] != saurabh[m])
            {
                flag = 1;
                break;
            }
            i++;
            m--;
        }
        if(flag == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};