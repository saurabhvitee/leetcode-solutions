class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>> ans;

        // Sort the Array cause what we want is 
        // Sorted Array where we can traverse and apply
        // 2 pointers technique
        // O(N^3) + O(NlogN)
        sort(nums.begin(), nums.end());

        for(int i=0; i<n-3; i++){

            // ignore same element and increase the counter i
            if(i>0 && (nums[i-1] == nums[i])) continue;

            for(int j=i+1; j<n-2; j++){
                
                //ignore same element and increase the counter j
                if (j> i+1 && (nums[j-1] == nums[j])) continue;

                // We will apply two pointers technique

                int k = j+1;
                int l = n-1;

                while(k<l){
                    long long sum = nums[i];
                    sum += nums[j];
                    sum += nums[k];
                    sum += nums[l];

                    if(sum < target){
                        k++;
                    }
                    else if(sum > target){
                        l--;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});

                        k++;
                        l--;

                        while(k<l && nums[k] == nums[k-1]) k++;
                        while(k<l && nums[l] == nums[l+1]) l--;
                    }
                }
            }
        }

        return ans;
    }
};