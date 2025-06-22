class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size();

        stack<char> st;
        st.push(s[0]);

        for (int i = 1; i < n; i++) {
            if (!st.empty()) {
                char top = st.top();
                if (s[i] == top) {
                    cout << "Popping " << top << endl;
                    st.pop();
                    continue;
                }
            }
            cout << "Pushing " << s[i] << endl;
            st.push(s[i]);
        }

        string newStr = "";
        while (!st.empty()) {
            cout << st.top() << endl;
            newStr += st.top();
            st.pop();
        }
        reverse(newStr.begin(), newStr.end());
        
        return newStr;
    }
};