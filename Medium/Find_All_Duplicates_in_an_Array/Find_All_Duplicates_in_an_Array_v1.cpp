class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n,0);
        for(int i=0;i<n;i++){
            ans[nums[i]-1]++;
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
        ans.clear();
        for(int i=0;i<n;i++){
            if(nums[i]==2){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};