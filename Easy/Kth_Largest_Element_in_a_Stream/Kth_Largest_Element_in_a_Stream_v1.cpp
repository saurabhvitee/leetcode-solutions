class KthLargest {
public:
    int K;
    vector<int> arr;

    KthLargest(int k, vector<int>& nums) {
        arr = nums;
        K = k;
    }

    static int calculatePartition(vector<int>& arr, int low, int high) {

        // Choose pivot first of all.
        // int pivot = nums[high]; // we will always use last element as pivot
        // we can use random selection also

        // better method is to generate pivot index randomly
        swap(arr[(low + rand() % (high - low + 1))],
             arr[high]); // Calculate random pivot index and swap with right
        int pivot = arr[high];

        // Let's take a pointer to track all the elements less than to pivot
        int i = low;

        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }

        swap(arr[i], arr[high]);
        return i;
    }

    int add(int val) {
        arr.push_back(val);

        int n = arr.size();

        // since we need to find Kth largest we will calculate Kth smallest.
        // Modifying K accordingly.
        int k_smallest = n - K;

        int left = 0;
        int right = n - 1;

        while (left <= right) {
            int pivotIndex = calculatePartition(arr, left, right);

            if (pivotIndex == k_smallest)
                return arr[k_smallest];
            else if (pivotIndex < k_smallest)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }

        return -1;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */