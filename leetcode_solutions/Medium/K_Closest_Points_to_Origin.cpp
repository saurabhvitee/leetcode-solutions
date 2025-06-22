class Solution {
public:
    static int distance(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }

    static int partition(vector<vector<int>>& points, int left, int right) {
        // choose pivot randomly as right
        int pivotIndex = left + rand() % (right - left + 1);
        swap(points[pivotIndex], points[right]);
        
        int pivot = distance(points[right]);

        int i = left;
        for (int j = left; j < right; j++) {
            if (distance(points[j]) <= pivot) {
                swap(points[i], points[j]);
                i++;
            }
        }

        // replace pivot at it's correct index i
        swap(points[right], points[i]);
        return i; // return pivot index
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int left = 0;
        int right = points.size() - 1;

        while (left<=right) {
            int pivotIndex = partition(points, left, right);

            if (pivotIndex == k)
                break;
            else if (pivotIndex < k)
                left = pivotIndex + 1;
            else
                right = pivotIndex - 1;
        }

        // Return the first k elements of the partially sorted vector
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};