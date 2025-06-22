class Solution {
public:
    bool backspaceCompare(string s, string t) {

        // Version 1 where we will use stack O(n) space
        cout << (build(s));
        cout << " " << (build(t));
        return build(s) == build(t);
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