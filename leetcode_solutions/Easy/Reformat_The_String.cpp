class Solution {
public:
    string reformat(string s) 
    {
        int l = s.length();
        int dc=0;
        int ac = 0;
        string digit = "";
        int i = 0;
        string alpha = "";
        while(i < l)
        {
            if(isdigit(s[i])){
                digit+=s[i];
                dc++;
            }
            else{
                alpha+=s[i];
                ac++;
            }
            i++;
        }
        string res = "";
        if(abs(dc-ac)>1){
            return res;
        }
        string ans="";
        string ans1="";
        int flag = 0;
        if(dc>ac){
            flag = 1;
            int j = 0;
            int k=0;
            int p = 0;
            while(j<l)
            {
                if(j%2==0){
                    ans+=digit[k];
                    k++;
                }else{
                    ans+=alpha[p];
                    p++;
                }
                j++;
            }
        }
        else{
            flag = 0;
            int u = 0;
            int v = 0;
            int w =0;
            while(u<l)
            {
                if(u%2==0){
                    ans1+=alpha[v];
                    v++;
                }
                else{
                    ans1+=digit[w];
                    w++;
                }
                u++;
            }
        }
        
        if(flag==1){
            return ans;
        }else{
            return ans1;
        }
        
    }
};