class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0;
        int j=0;
        int prod = 1;
        int res = 0;
        while(i<=j){
            if(i<nums.size() && i==j && prod*nums[i]>=k){
                i++;
                j++;
                continue;
            }
            while(j<nums.size() && prod*nums[j] < k){
                prod*=nums[j];
                j++;
            }
            res+=j-i;
            if(i<nums.size())
                prod/=nums[i];
            i++; 
        }
        return res;
    }
};