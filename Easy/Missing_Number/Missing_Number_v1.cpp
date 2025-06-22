class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int res=n;
        int i=0;
        while(i<n){
           res = res^nums[i];
            {
                res = res^i;
            }
            i++;
        }
        return res;
    }
};