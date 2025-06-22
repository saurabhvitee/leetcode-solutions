class Solution {
public:
    int maximumProduct(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = nums[n-1]*nums[n-2]*nums[n-3];
        int ans1 = nums[n-1]*nums[0]*nums[1];
        
        if(ans > ans1)
        {
            return ans;
        }
        else
        {
            return ans1;
        }
        
    }
};