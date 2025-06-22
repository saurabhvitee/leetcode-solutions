class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        int n = arr.size();
        int prefix[n];
        prefix[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            prefix[i] = max(prefix[i-1],arr[i]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(prefix[i] == i)
            {
                cnt++;
            }
        }
        return cnt;
    }
};