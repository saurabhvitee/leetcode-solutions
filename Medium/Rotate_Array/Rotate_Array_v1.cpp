class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int n = nums.size();
        k = k%n;
        int d = n-k;
        int i = 0;
        int j = d-1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        i = d;
        j = n-1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
        i = 0;
        j = n-1;
        while(i<j)
        {
            swap(nums[i],nums[j]);
            i++;
            j--;
        }
    }
};