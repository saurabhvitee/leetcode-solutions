class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> warmerDays(temperatures.size());
        stack<int> st;

        int n = temperatures.size();

        for(int i=0; i<n; i++){

            while(!st.empty() and temperatures[st.top()] < temperatures[i]){

                // Fetching top element from stack 
                // setting up currentElement as answer for that top
                // popping it
                int j = st.top();
                warmerDays[j] = i-j;
                st.pop();
            }

            // We are storing index only in stack 
            // Whenever we will pop from stack we will update currentIndex - j;
            // Answer for this particular index
            st.push(i);
        }


        // whatever is left in stack, answer will be zero for all those
        return warmerDays;
    }
};