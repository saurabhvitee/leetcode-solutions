class Solution {
public:
    string removeDuplicates(string s) {

        int n = s.size();

        // Bruteforce version - using stack, store chars, reverse

        // stack<char> st;
        // st.push(s[0]);

        // for (int i = 1; i < n; i++) {
        //     if (!st.empty()) {
        //         char top = st.top();
        //         if (s[i] == top) {
        //             cout << "Popping " << top << endl;
        //             st.pop();
        //             continue;
        //         }
        //     }
        //     cout << "Pushing " << s[i] << endl;
        //     st.push(s[i]);
        // }

        // string newStr = "";
        // while (!st.empty()) {
        //     cout << st.top() << endl;
        //     newStr += st.top();
        //     st.pop();
        // }
        // reverse(newStr.begin(), newStr.end());

        // return newStr;


        // Optimized version - directly use string as stack in C++ 
        // since string data structure in C++ is mutable from both side
        
        string newStr = "";

        for(char c : s){
            if(!newStr.empty() && c == newStr.back()){
                newStr.pop_back();
                // Here we are removing duplicate adjacents
            }else{
                // otherwise append this in string 
                newStr.push_back(c);
            }
        }

        return newStr;
    }
};