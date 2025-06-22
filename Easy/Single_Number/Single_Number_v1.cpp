class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int i;
        int result=nums[0];
        for(i=1;i<nums.size();i++){
            result = result^nums[i];
        }
        return result;

}
};