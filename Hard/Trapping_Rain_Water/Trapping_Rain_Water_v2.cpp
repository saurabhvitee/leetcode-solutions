class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int leftMax = 0;
        int rightMax = 0;

        // Take 2 pointers
        int left=0;
        int right=height.size()-1;

        while(left < right){
            // So basically here we are ensuring there is something bigger than
            // height[left] in right
            // leftMax is a function of height[left] hence we can say
            // there will be something in right bigger than leftMax 
            // so we can freely calculate answer 

            if(height[left] < height[right]){
                leftMax = max(height[left], leftMax);
                ans += (leftMax-height[left]);
                left++;
            }else{

                // Similarly we are maintaing rightMax but only if there is something
                // bigger than height[right] exists in left and rightMax is function of
                // height[right] so there will always be something bigger in left
                // bigger than height[right] so we can safely calculate our answer. 
                rightMax = max(height[right], rightMax);
                ans += (rightMax-height[right]);
                right--;
            }
        }
        return ans;
    }
};