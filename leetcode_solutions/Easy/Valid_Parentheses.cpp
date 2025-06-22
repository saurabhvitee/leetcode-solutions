class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {

            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } else {
                if (!st.empty()) {
                    char bracketAtTop = st.top();
                    if (s[i] == ')' and bracketAtTop == '(') {
                        st.pop();
                    } else if (s[i] == '}' and bracketAtTop == '{') {
                        st.pop();
                    } else if (s[i] == ']' and bracketAtTop == '[') {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    // This is very important condition
                    // Stack should not be empty if we are coming to a closing bracket 
                    // Means there will always be one invalid parentheses
                    return false;
                }
            }
        }

        return st.empty();
    }
};