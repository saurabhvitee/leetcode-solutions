class KthLargest {
public:
    int K;
    vector<int> arr;

    KthLargest(int k, vector<int>& nums) {
        K = k;
        arr = nums;
    }

    static int calculatePartition(vector<int>& arr, int low, int high) {
        // Randomly choose a pivot and move it to the end
        swap(arr[low + rand() % (high - low + 1)], arr[high]);
        int pivot = arr[high];

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
        int k_smallest = n - K; // we want K-th largest = (n - K)-th smallest

        int left = 0, right = n - 1;

        while (left <= right) {
            int pivotIndex = calculatePartition(arr, left, right);

            if (pivotIndex == k_smallest)
                return arr[pivotIndex];
            else if (pivotIndex < k_smallest)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }

        return -1; // fallback (shouldn't reach here)
    }
};
