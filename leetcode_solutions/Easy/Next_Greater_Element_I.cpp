class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mpp;
        stack<int> st;

        int n2 = nums2.size();

        for (int i = 0; i < n2; i++) {
            while (!st.empty() and nums2[i] > st.top()) {
                mpp[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        while (!st.empty()) {
            mpp[st.top()] = -1;
            st.pop();
        }

        int n1 = nums1.size();

        for (int i = 0; i < n1; i++) {
            nums1[i] = mpp[nums1[i]];
        }

        return nums1;
    }
};