class Solution {
public:
    bool backspaceCompare(string s, string t) {

        // Version 1 where we will use stack O(n) space
        // return build(s) == build(t);

        // Version 2 where we will solve this in O(1) space
        int n = s.size();
        int m = t.size();

        int i=n-1, j=m-1;
        int skipS = 0;
        int skipT = 0;

        while(i >= 0 || j >= 0){
            
            while(i >= 0){
                if(s[i] == '#') skipS++, i--;
                else if(skipS > 0) skipS--, i--;
                else break;
            }

            while(j >= 0){
                if(t[j] == '#') skipT++, j--;
                else if(skipT > 0) skipT--, j--;
                else break;
            }

            if(i>=0 && j>=0 && s[i] != t[j]) return false;

            // if ((i >= 0) != (j >= 0))
            //     return false;

            i--;
            j--;
        }

        return i==j;
    }

    string build(string str){
        
        string st = "";

        for(char c: str){
            if(c == '#' && !st.empty()){
                st.pop_back();
            }else if(c != '#'){
                st.push_back(c);
            }
        }

        return st;
    }
};