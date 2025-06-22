class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N,1);
        for(int i=1;i<N;i++){
            res[i]=res[i-1]*nums[i-1];
        }
        int right=1;
        
        for(int i=N-1;i>=0;i--){
            res[i]=res[i]*right;
            right = right*nums[i];
        }
        return res;
    }
};