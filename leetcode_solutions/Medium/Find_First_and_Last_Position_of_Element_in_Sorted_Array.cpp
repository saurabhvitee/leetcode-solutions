class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int lb=-1;
        int ub=-1;
        int s=0;
        int e = nums.size()-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(nums[mid]==target){
                lb=mid;
                e=mid-1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        ans.push_back(lb);
        s=0;
        e=nums.size()-1;
        while(s<=e)
        {
            int mid = (s+e)/2;
            if(nums[mid]==target){
                ub=mid;
                s=mid+1;
            }
            else if(nums[mid]>target){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        ans.push_back(ub);
        return ans;
    }
};