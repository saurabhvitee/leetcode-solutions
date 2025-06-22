class Solution {
public:

    void merge(vector<int> &nums, int low, int mid, int high){

        // temp array
        vector<int> temp;

        int i=low;
        int j=mid+1;

        while(i<=mid && j<=high){
            if(nums[i] < nums[j]){
                temp.push_back(nums[i]);
                i++;
            }else{
                temp.push_back(nums[j]);
                j++;
            }
        }

        while(i<=mid) temp.push_back(nums[i]), i++;
        while(j<=high) temp.push_back(nums[j]), j++;

        // transfer all the elements in arr again

        for(int i=low; i<=high; i++){
            nums[i] = temp[i-low];
        }
    }

    int countPairs(vector<int> &nums, int low, int mid, int high){
        int count = 0;
        int j = mid+1; // this will start from mid+1
        for(int i=low; i<=mid; i++){
            // chances of integer overflow since nums[i] is ranging from full int range
            // if we multiply this by 2 then surely it is going to overflow
            while(j<=high && (nums[i] > 2LL*nums[j])){
                j++;
            }
            count += (j-(mid+1));
        }

        return count;
    }

    int mergeSort(vector<int> &nums, int low, int high){

        int count = 0; // To count valid reverse pairs

        if (low >= high) return count; // base case

        int mid = (low+high)/2;

        count += mergeSort(nums, low, mid);
        count += mergeSort(nums, mid+1, high);

        count += countPairs(nums, low, mid, high); // Read comments below
        // since this question is an extended version of Inversion count
        // we are adding an extra step here so it does not mess up with actual merge sort algorithm

        merge(nums,low,mid,high);

        return count;

    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        return mergeSort(nums, 0, n-1);
    }
};