class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int left[n];
        int right[n];
        left[0]=nums[0];
        right[n-1]=nums[n-1];
        int i;
        for(i=1;i<n;i++){
            left[i]=nums[i]-nums[i-1];
        }
        for(i=n-2;i>=0;i--){
            right[i]=nums[i]-nums[i+1];
        }
        for(i=0;i<n;i++){
            if(left[i]>0 && right[i]>0){
                break;
            }
        }
        if(nums.size()==1){
            return 0;
        }
        if(nums.size()==2){
            if(nums[0]>nums[1])
                return 0;
            else
                return 1;
        }
        return i;
    }
};