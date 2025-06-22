class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int f=1;
        int b=1;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            f=f*nums[i];
            b=b*nums[n-i-1];
            ans = max(ans,max(b,f));
            if(f==0){
                f=1;
            }
            if(b==0){
                b=1;
            }
        }
        return ans;
    }
};