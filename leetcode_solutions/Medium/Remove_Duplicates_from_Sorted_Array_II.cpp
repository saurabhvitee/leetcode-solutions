class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        int j=0;
        int count=0;

        for(int i=1; i<n; i++){
            // Basically I am checking if my new nums[i] is different from
            // my last saved unique element
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
                count = 0;
            }
            else if(count != 1 && (nums[i] == nums[j])){
                j++;
                nums[j] = nums[i];
                count++;
            }
        }

        return j+1;
    }
};
