class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        if(n==0)
        {
            return 0;
        }
        int ans = 0;
        int left[n];
        int right[n];
        left[0] = height[0];
        for(int i=1;i<n;i++)
        {
            left[i] = max(left[i-1],height[i]);
        }
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(right[i+1],height[i]);
        }
        for(int i=0;i<n;i++)
        {
            int d = min(left[i],right[i]);
            int res = d - height[i];
            ans+=res;
        }
        return ans;
    }
};