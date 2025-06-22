class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int l = nums.size();
        set<int> s;
        for(int i=0;i<l;i++){
            s.insert(nums[i]);
        }
        if(s.size()==nums.size()){
            return false;
        }else{
            return true;
        }
    }
};